#include <assert.h>
#include <stdio.h>
#include "../core/api.h"
#include "../shaders/pbr_shader.h"
#include "pbr_scenes.h"

scene_t *pbr_assassin_scene(void) {
    const char *meshes[] = {
        "assets/assassin/body.obj",
        "assets/assassin/face.obj",
        "assets/assassin/hair.obj",
        "assets/assassin/weapon.obj",
    };
    const char *skeleton = "assets/assassin/assassin.ani";
    pbrm_material_t materials[] = {
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/assassin/body_basecolor.tga",
            "assets/assassin/body_metalness.tga",
            "assets/assassin/body_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, 0, 0.9f,
            "assets/assassin/face_basecolor.tga",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/assassin/hair_basecolor.tga",
            "assets/assassin/hair_metalness.tga",
            "assets/assassin/hair_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/assassin/weapon_basecolor.tga",
            "assets/assassin/weapon_metalness.tga",
            "assets/assassin/weapon_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
    };
    vec4_t background = vec4_new(0.196f, 0.196f, 0.196f, 1);
    const char *env_name = "papermill";
    mat4_t scale, translation, root;
    int num_meshes = ARRAY_SIZE(meshes);
    model_t **models = NULL;
    model_t *model;
    int i;

    assert(ARRAY_SIZE(materials) == num_meshes);

    translation = mat4_translate(0, -125.815f, 18.898f);
    scale = mat4_scale(0.0038f, 0.0038f, 0.0038f);
    root = mat4_mul_mat4(scale, translation);
    for (i = 0; i < num_meshes; i++) {
        model = pbrm_create_model(meshes[i], skeleton, root,
                                  materials[i], env_name);
        darray_push(models, model);
    }

    return scene_create(background, NULL, models, 1, 1, 0);
}

scene_t *pbr_centaur_scene(void) {
    const char *meshes[] = {
        "assets/centaur/body.obj",
        "assets/centaur/flame.obj",
        "assets/centaur/gas.obj",
    };
    pbrs_material_t materials[] = {
        {
            {1, 1, 1, 1}, {1, 1, 1}, 0.6f,
            "assets/centaur/body_diffuse.tga",
            "assets/centaur/body_specular.tga",
            NULL,
            NULL,
            "assets/centaur/body_occlusion.tga",
            "assets/centaur/body_emission.tga",
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, {0, 0, 0}, 0,
            "assets/centaur/flame_diffuse.tga",
            NULL,
            NULL,
            NULL,
            NULL,
            "assets/centaur/flame_emission.tga",
            0, 1, 0,
        },
        {
            {1, 1, 1, 1}, {1, 1, 1}, 0.6f,
            "assets/centaur/gas_diffuse.tga",
            "assets/centaur/gas_specular.tga",
            NULL,
            NULL,
            "assets/centaur/gas_occlusion.tga",
            NULL,
            0, 0, 0,
        },
    };
    vec4_t background = vec4_new(0.196f, 0.196f, 0.196f, 1);
    const char *env_name = "papermill";
    mat4_t scale, rotation, translation, root;
    int num_meshes = ARRAY_SIZE(meshes);
    model_t **models = NULL;
    model_t *model;
    int i;

    assert(ARRAY_SIZE(materials) == num_meshes);

    translation = mat4_translate(0.154f, -7.579f, -30.749f);
    rotation = mat4_rotate_x(TO_RADIANS(-90));
    rotation = mat4_mul_mat4(mat4_rotate_y(TO_RADIANS(-90)), rotation);
    scale = mat4_scale(0.016f, 0.016f, 0.016f);
    root = mat4_mul_mat4(scale, mat4_mul_mat4(rotation, translation));
    for (i = 0; i < num_meshes; i++) {
        model = pbrs_create_model(meshes[i], NULL, root,
                                  materials[i], env_name);
        darray_push(models, model);
    }

    return scene_create(background, NULL, models, 1, 1, 0);
}

scene_t *pbr_dieselpunk_scene(void) {
    const char *meshes[] = {
        "assets/dieselpunk/ground.obj",
        "assets/dieselpunk/mech.obj",
        "assets/dieselpunk/yingham.obj",
    };
    pbrm_material_t materials[] = {
        {
            {1, 1, 1, 1}, 0, 1,
            "assets/dieselpunk/ground_basecolor.tga",
            NULL,
            "assets/dieselpunk/ground_roughness.tga",
            NULL,
            NULL,
            NULL,
            1, 1, 0,
        },
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/dieselpunk/mech_basecolor.tga",
            "assets/dieselpunk/mech_metalness.tga",
            "assets/dieselpunk/mech_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, 0, 1,
            "assets/dieselpunk/yingham_basecolor.tga",
            NULL,
            "assets/dieselpunk/yingham_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
    };
    vec4_t background = vec4_new(0.196f, 0.196f, 0.196f, 1);
    const char *env_name = "papermill";
    mat4_t scale, rotation, translation, root;
    int num_meshes = ARRAY_SIZE(meshes);
    model_t **models = NULL;
    model_t *model;
    int i;

    assert(ARRAY_SIZE(materials) == num_meshes);

    translation = mat4_translate(1.036f, -114.817f, 27.682f);
    rotation = mat4_rotate_y(TO_RADIANS(-90));
    scale = mat4_scale(0.0012f, 0.0012f, 0.0012f);
    root = mat4_mul_mat4(scale, mat4_mul_mat4(rotation, translation));
    for (i = 0; i < num_meshes; i++) {
        model = pbrm_create_model(meshes[i], NULL, root,
                                  materials[i], env_name);
        darray_push(models, model);
    }

    return scene_create(background, NULL, models, 1, 1, 0);
}

scene_t *pbr_drone_scene(void) {
    const char *mesh = "assets/drone/drone.obj";
    const char *skeleton = "assets/drone/drone.ani";
    pbrs_material_t material = {
        {1, 1, 1, 1}, {1, 1, 1}, 1,
        "assets/drone/drone_diffuse.tga",
        "assets/drone/drone_specular.tga",
        "assets/drone/drone_glossiness.tga",
        NULL,
        "assets/drone/drone_occlusion.tga",
        "assets/drone/drone_emission.tga",
        0, 0, 0,
    };
    vec4_t background = vec4_new(0.196f, 0.196f, 0.196f, 1);
    const char *env_name = "papermill";
    model_t **models = NULL;

    mat4_t translation = mat4_translate(0, -79.181f, -4.447f);
    mat4_t rotation = mat4_rotate_y(TO_RADIANS(180));
    mat4_t scale = mat4_scale(0.0028f, 0.0028f, 0.0028f);
    mat4_t root = mat4_mul_mat4(scale, mat4_mul_mat4(rotation, translation));
    model_t *model = pbrs_create_model(mesh, skeleton, root,
                                       material, env_name);
    darray_push(models, model);

    return scene_create(background, NULL, models, 1, 1, 0);
}

scene_t *pbr_gunslinger_scene(void) {
    const char *meshes[] = {
        "assets/gunslinger/gunslinger.obj",
        "assets/gunslinger/revolver.obj",
    };
    pbrs_material_t materials[] = {
        {
            {1, 1, 1, 1}, {0.56f, 0.56f, 0.56f}, 1,
            "assets/gunslinger/gunslinger_diffuse.tga",
            "assets/gunslinger/gunslinger_specular.tga",
            NULL,
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, {0.64f, 0.64f, 0.64f}, 0.78f,
            "assets/gunslinger/revolver_diffuse.tga",
            "assets/gunslinger/revolver_specular.tga",
            NULL,
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
    };
    vec4_t background = vec4_new(0.196f, 0.196f, 0.196f, 1);
    const char *env_name = "papermill";
    mat4_t scale, rotation, translation, root;
    int num_meshes = ARRAY_SIZE(meshes);
    model_t **models = NULL;
    model_t *model;
    int i;

    assert(ARRAY_SIZE(materials) == num_meshes);

    translation = mat4_translate(-0.520f, 1.196f, 2.670f);
    rotation = mat4_rotate_x(TO_RADIANS(-90));
    scale = mat4_scale(0.023f, 0.023f, 0.023f);
    root = mat4_mul_mat4(scale, mat4_mul_mat4(rotation, translation));
    for (i = 0; i < num_meshes; i++) {
        model = pbrs_create_model(meshes[i], NULL, root,
                                  materials[i], env_name);
        darray_push(models, model);
    }

    return scene_create(background, NULL, models, 1, 1, 0);
}

scene_t *pbr_helmet_scene(void) {
    const char *mesh = "assets/helmet/helmet.obj";
    pbrm_material_t material = {
        {1, 1, 1, 1}, 1, 1,
        "assets/helmet/helmet_basecolor.tga",
        "assets/helmet/helmet_metalness.tga",
        "assets/helmet/helmet_roughness.tga",
        NULL,
        "assets/helmet/helmet_occlusion.tga",
        "assets/helmet/helmet_emission.tga",
        0, 0, 0,
    };
    vec4_t background = vec4_new(0.196f, 0.196f, 0.196f, 1);
    const char *env_name = "papermill";
    model_t **models = NULL;

    mat4_t translation = mat4_translate(0.002f, 0.187f, 0);
    mat4_t rotation = mat4_rotate_x(TO_RADIANS(90));
    mat4_t scale = mat4_scale(0.5f, 0.5f, 0.5f);
    mat4_t root = mat4_mul_mat4(scale, mat4_mul_mat4(rotation, translation));
    model_t *model = pbrm_create_model(mesh, NULL, root, material, env_name);
    darray_push(models, model);

    return scene_create(background, NULL, models, 1, 1, 0);
}

scene_t *pbr_helmet2_scene(void) {
    const char *meshes[] = {
        "assets/helmet2/glass.obj",
        "assets/helmet2/helmet.obj",
    };
    pbrm_material_t materials[] = {
        {
            {0.336f, 0.336f, 0.336f, 0.306f}, 0.725f, 0.240f,
            NULL,
            NULL,
            "assets/helmet2/glass_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 1, 0,
        },
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/helmet2/helmet_basecolor.tga",
            "assets/helmet2/helmet_metalness.tga",
            "assets/helmet2/helmet_roughness.tga",
            NULL,
            "assets/helmet2/helmet_occlusion.tga",
            "assets/helmet2/helmet_emission.tga",
            0, 0, 0,
        },
    };
    vec4_t background = vec4_new(0.196f, 0.196f, 0.196f, 1);
    const char *env_name = "papermill";
    int num_meshes = ARRAY_SIZE(meshes);
    model_t **models = NULL;
    model_t *model;
    mat4_t root;
    int i;

    assert(ARRAY_SIZE(materials) == num_meshes);

    root = mat4_scale(0.5f, 0.5f, 0.5f);
    for (i = 0; i < num_meshes; i++) {
        model = pbrm_create_model(meshes[i], NULL, root,
                                  materials[i], env_name);
        darray_push(models, model);
    }

    return scene_create(background, NULL, models, 1, 1, 0);
}

scene_t *pbr_junkrat_scene(void) {
    const char *skeleton = "assets/junkrat/junkrat.ani";
    pbrm_material_t materials[] = {
        {
            {1, 1, 1, 1}, 1, 0.6f,
            "assets/junkrat/upper_basecolor.tga",
            "assets/junkrat/upper_metalness.tga",
            NULL,
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, 1, 0.6f,
            "assets/junkrat/lower_basecolor.tga",
            "assets/junkrat/lower_metalness.tga",
            NULL,
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, 0, 1,
            "assets/junkrat/head_basecolor.tga",
            NULL,
            "assets/junkrat/head_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, 1, 0.6f,
            "assets/junkrat/back_basecolor.tga",
            "assets/junkrat/back_metalness.tga",
            NULL,
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
    };
    int mesh2material[63] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 2, 0, 1, 0, 2, 1,
        0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2,
    };
    vec4_t background = vec4_new(0.196f, 0.196f, 0.196f, 1);
    const char *env_name = "papermill";
    mat4_t scale, translation, root;
    int num_meshes = ARRAY_SIZE(mesh2material);
    model_t **models = NULL;
    model_t *model;
    int i;

    translation = mat4_translate(3.735f, -382.993f, 57.980f);
    scale = mat4_scale(0.0013f, 0.0013f, 0.0013f);
    root = mat4_mul_mat4(scale, translation);
    for (i = 0; i < num_meshes; i++) {
        int material_index = mesh2material[i];
        pbrm_material_t material = materials[material_index];
        const char *obj_template = "assets/junkrat/junkrat%d.obj";
        char obj_filename[64];
        sprintf(obj_filename, obj_template, i);
        model = pbrm_create_model(obj_filename, skeleton, root,
                                  material, env_name);
        darray_push(models, model);
    }

    return scene_create(background, NULL, models, 1, 1, 0);
}

scene_t *pbr_ornitier_scene(void) {
    const char *meshes[] = {
        "assets/ornitier/base.obj",
        "assets/ornitier/body.obj",
        "assets/ornitier/coat.obj",
        "assets/ornitier/feuga.obj",
        "assets/ornitier/hands.obj",
        "assets/ornitier/hat.obj",
        "assets/ornitier/legs.obj",
    };
    pbrm_material_t materials[] = {
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/ornitier/base_basecolor.tga",
            "assets/ornitier/base_metalness.tga",
            "assets/ornitier/base_roughness.tga",
            NULL,
            NULL,
            "assets/ornitier/base_emission.tga",
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/ornitier/body_basecolor.tga",
            NULL,
            NULL,
            NULL,
            NULL,
            "assets/ornitier/body_emission.tga",
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/ornitier/coat_basecolor.tga",
            "assets/ornitier/coat_metalness.tga",
            "assets/ornitier/coat_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
        {
            {0.8f, 0.8f, 0.8f, 0.84f}, 0, 0.04f,
            "assets/ornitier/feuga_basecolor.tga",
            NULL,
            NULL,
            NULL,
            NULL,
            "assets/ornitier/feuga_emission.tga",
            0, 1, 0,
        },
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/ornitier/hands_basecolor.tga",
            "assets/ornitier/hands_metalness.tga",
            "assets/ornitier/hands_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/ornitier/hat_basecolor.tga",
            "assets/ornitier/hat_metalness.tga",
            "assets/ornitier/hat_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/ornitier/legs_basecolor.tga",
            "assets/ornitier/legs_metalness.tga",
            "assets/ornitier/legs_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
    };
    vec4_t background = vec4_new(0.196f, 0.196f, 0.196f, 1);
    const char *env_name = "papermill";
    mat4_t scale, translation, root;
    int num_meshes = ARRAY_SIZE(meshes);
    model_t **models = NULL;
    model_t *model;
    int i;

    assert(ARRAY_SIZE(materials) == num_meshes);

    translation = mat4_translate(-111.550f, -67.795f, 178.647f);
    scale = mat4_scale(0.00095f, 0.00095f, 0.00095f);
    root = mat4_mul_mat4(scale, translation);
    for (i = 0; i < num_meshes; i++) {
        model = pbrm_create_model(meshes[i], NULL, root,
                                  materials[i], env_name);
        darray_push(models, model);
    }

    return scene_create(background, NULL, models, 1, 1, 0);
}

scene_t *pbr_ponycar_scene(void) {
    const char *meshes[] = {
        "assets/ponycar/body.obj",
        "assets/ponycar/ground.obj",
        "assets/ponycar/interior.obj",
        "assets/ponycar/windows.obj",
    };
    pbrm_material_t materials[] = {
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/ponycar/body_basecolor.tga",
            "assets/ponycar/body_metalness.tga",
            "assets/ponycar/body_roughness.tga",
            NULL,
            NULL,
            "assets/ponycar/body_emission.tga",
            0, 0, 0,
        },
        {
            {0, 0, 0, 1}, 0, 1,
            "assets/ponycar/ground_basecolor.tga",
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            1, 1, 0,
        },
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/ponycar/interior_basecolor.tga",
            "assets/ponycar/interior_metalness.tga",
            "assets/ponycar/interior_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 0, 0,
        },
        {
            {1, 1, 1, 0.73f}, 0, 1,
            "assets/ponycar/body_basecolor.tga",
            "assets/ponycar/body_metalness.tga",
            "assets/ponycar/body_roughness.tga",
            NULL,
            NULL,
            NULL,
            0, 1, 0,
        },
    };
    vec4_t background = vec4_new(0.196f, 0.196f, 0.196f, 1);
    const char *env_name = "papermill";
    mat4_t scale, rotation, translation, root;
    int num_meshes = ARRAY_SIZE(meshes);
    model_t **models = NULL;
    model_t *model;
    int i;

    assert(ARRAY_SIZE(materials) == num_meshes);

    translation = mat4_translate(-10.343f, -13.252f, -186.343f);
    rotation = mat4_rotate_x(TO_RADIANS(-90));
    scale = mat4_scale(0.0015f, 0.0015f, 0.0015f);
    root = mat4_mul_mat4(scale, mat4_mul_mat4(rotation, translation));
    for (i = 0; i < num_meshes; i++) {
        model = pbrm_create_model(meshes[i], NULL, root,
                                  materials[i], env_name);
        darray_push(models, model);
    }

    return scene_create(background, NULL, models, 1, 1, 0);
}

scene_t *pbr_spitfire_scene(void) {
    const char *meshes[] = {
        "assets/spitfire/body.obj",
        "assets/spitfire/windows.obj",
    };
    pbrm_material_t materials[] = {
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/spitfire/spitfire_basecolor.tga",
            "assets/spitfire/spitfire_metalness.tga",
            "assets/spitfire/spitfire_roughness.tga",
            NULL,
            "assets/spitfire/spitfire_occlusion.tga",
            NULL,
            0, 0, 0,
        },
        {
            {1, 1, 1, 1}, 1, 1,
            "assets/spitfire/spitfire_basecolor.tga",
            "assets/spitfire/spitfire_metalness.tga",
            "assets/spitfire/spitfire_roughness.tga",
            NULL,
            "assets/spitfire/spitfire_occlusion.tga",
            NULL,
            0, 1, 0,
        },
    };
    vec4_t background = vec4_new(0.196f, 0.196f, 0.196f, 1);
    const char *env_name = "papermill";
    mat4_t scale, rotation, translation, root;
    int num_meshes = ARRAY_SIZE(meshes);
    model_t **models = NULL;
    model_t *model;
    int i;

    assert(ARRAY_SIZE(materials) == num_meshes);

    translation = mat4_translate(0, 2.012f, -79.074f);
    rotation = mat4_rotate_x(TO_RADIANS(-90));
    rotation = mat4_mul_mat4(mat4_rotate_y(TO_RADIANS(90)), rotation);
    scale = mat4_scale(0.0024f, 0.0024f, 0.0024f);
    root = mat4_mul_mat4(scale, mat4_mul_mat4(rotation, translation));
    for (i = 0; i < num_meshes; i++) {
        model = pbrm_create_model(meshes[i], NULL, root,
                                  materials[i], env_name);
        darray_push(models, model);
    }

    return scene_create(background, NULL, models, 1, 1, 0);
}
