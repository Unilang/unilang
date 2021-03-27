#include "include/blah.h"
using namespace Blah;

Batch batch;
TextureRef tex;

void startup()
{
    //tex = Texture::create("player.png");
}

void render()
{
    App::backbuffer->clear(Color::black);
    
    auto center = Vec2(App::backbuffer->width(), App::backbuffer->height()) / 2;
    auto rotation = Time::elapsed * Calc::TAU;
    auto transform = Mat3x2::create_transform(center, Vec2::zero, Vec2::one, rotation);

    batch.push_matrix(transform);
    batch.rect(Rect(-32, -32, 64, 64), Color::red);
    //batch.tex(tex, Vec2(64, 0), Color::white);
    batch.pop_matrix();
    
    batch.render();
    batch.clear();
}

int main()
{
    Config config;
    config.name = "blah app";
    config.width = 1280;
    config.height = 720;
    config.on_startup = startup;
    config.on_render = render;
    
    App::run(&config);
    return 0;
}