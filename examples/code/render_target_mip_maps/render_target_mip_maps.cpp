#include "../example_common.h"

using namespace put;
using namespace ecs;

namespace pen
{
    pen_creation_params pen_entry(int argc, char** argv)
    {
        pen::pen_creation_params p;
        p.window_width = 1280;
        p.window_height = 720;
        p.window_title = "render_target_mip_maps";
        p.window_sample_count = 4;
        p.user_thread_function = user_entry;
        p.flags = pen::e_pen_create_flags::renderer;
        return p;
    }
} // namespace pen

void mip_ui()
{
    bool opened = true;
    ImGui::Begin("Render Target Mip Maps", &opened, ImGuiWindowFlags_AlwaysAutoResize);

    const pmfx::render_target* r = pmfx::get_render_target(PEN_HASH("mip_mapped"));
    if (!r)
        return;

    f32 w, h;
    u32 div = 2;
    for (u32 i = 0; i < 8; ++i)
    {
        pmfx::get_render_target_dimensions(r, w, h);
        ImVec2 size(w / div, h / div);
        ImGui::Image(IMG(r->handle), size);

        if (i % 4 != 0)
            ImGui::SameLine();

        div <<= 1;
    }

    ImGui::End();
}

void example_setup(ecs::ecs_scene* scene, camera& cam)
{
    scene->view_flags &= ~e_scene_view_flags::hide_debug;
    put::dev_ui::enable(true);

    pmfx::init("data/configs/render_target_mip_maps.jsn");

    clear_scene(scene);

    material_resource* default_material = get_material_resource(PEN_HASH("default_material"));
    geometry_resource* box_resource = get_geometry_resource(PEN_HASH("cube"));

    // add light
    u32 light = get_new_entity(scene);
    scene->names[light] = "front_light";
    scene->id_name[light] = PEN_HASH("front_light");
    scene->lights[light].colour = vec3f::one();
    scene->lights[light].direction = vec3f::one();
    scene->lights[light].type = e_light_type::dir;
    scene->transforms[light].translation = vec3f::zero();
    scene->transforms[light].rotation = quat();
    scene->transforms[light].scale = vec3f::one();
    scene->entities[light] |= e_cmp::light;
    scene->entities[light] |= e_cmp::transform;

    // add some boxes
    f32   num_pillar_rows = 5;
    f32   d = 50.0f * 0.5f;
    vec3f start_pos = vec3f(-d, -d, -d);
    vec3f pos = start_pos;
    for (s32 i = 0; i < num_pillar_rows; ++i)
    {
        pos.x = start_pos.x;

        for (s32 i = 0; i < num_pillar_rows; ++i)
        {
            pos.z = start_pos.z;

            for (s32 j = 0; j < num_pillar_rows; ++j)
            {
                u32 pillar = get_new_entity(scene);
                scene->transforms[pillar].rotation = quat();
                scene->transforms[pillar].scale = vec3f(2.0f, 2.0f, 2.0f);
                scene->transforms[pillar].translation = pos;
                scene->parents[pillar] = pillar;
                scene->entities[pillar] |= e_cmp::transform;

                instantiate_geometry(box_resource, scene, pillar);
                instantiate_material(default_material, scene, pillar);
                instantiate_model_cbuffer(scene, pillar);

                pos.z += d / 2;
            }

            pos.x += d / 2;
        }

        pos.y += d / 2;
    }
}

void example_update(ecs::ecs_scene* scene, camera& cam, f32 dt)
{
    mip_ui();
}
