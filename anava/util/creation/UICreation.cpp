//
// Created by Alexander Farrell on 7/4/22.
//

#include "UICreation.h"
#include "../../io/ui/Button.h"

Noun *UICreation::CreateImage(Texture* texture,
                              float size) {
    return UICreation::CreateImage(texture, size, size);
}

Noun *UICreation::CreateText(Font* font,
                             const std::string& text) {
    auto noun = App::engine_app->universe->focused->create_noun();
    noun->add_state(new Location());

    auto mesh = GeometryCreation::CreateText(font, text);

    auto material = new Material(App::engine_app->io->visual->shader_text);
    material->add_texture(font->texture);

    auto drawable = new Drawable(
            mesh,
            material,
            App::engine_app->io->visual->camera_ui
    );
//    drawable->blend = GL_ONE;
    App::engine_app->io->visual->add_drawable(drawable);
    noun->add_state(drawable);

    return noun;
}

Orthographic *UICreation::CreateCameraOrtho() {
    auto cameraNoun = App::engine_app->universe->focused->create_noun();
    auto camera = cameraNoun->add_state(
            new Orthographic(
                    (float)App::engine_app->player->window->getWidth(),
                    (float)App::engine_app->player->window->getHeight()
            )
    );
    return camera;
}

Perspective *UICreation::CreateCameraPerspective() {
    auto cameraNoun = App::engine_app->universe->focused->create_noun();
    auto camera = cameraNoun->add_state(
                new Perspective(
                        (float)App::engine_app->player->window->getWidth()/
                        (float)App::engine_app->player->window->getHeight()
                        )
    );
    return camera;
}

Noun *UICreation::CreateImage(Texture *texture, float width, float height) {
    auto noun = App::engine_app->universe->focused->create_noun();
    noun->add_state(new Location());

    auto mesh = GeometryCreation::CreateRectangle(width, height);

    auto material = new Material(App::engine_app->io->visual->shader_texture_unlit);
    material->add_texture(texture);

    auto drawable = new Drawable(
            mesh,
            material,
            App::engine_app->io->visual->camera_ui
    );
    App::engine_app->io->visual->add_drawable(drawable);
    noun->add_state(drawable);

    return noun;
}

Noun *UICreation::CreateButton(Font *font, const std::string &text, void (*on)()) {
    auto noun = UICreation::CreateText(font, text);
    auto button = new Button(on);
    button->xSize = (float)font->get_width(text);
    button->ySize = (float)font->font_size;
    noun->add_state(button);
    return noun;
}

