#include "ExampleScene.h"
#include "Random.h"

bool ExampleScene::Initialize() {
	m_renderer.Initialize();
	m_renderer.CreateWindow("Example", 800, 600);

	m_input.Initialize();
	m_input.Update();

	m_framebuffer = std::make_unique<Framebuffer>(m_renderer, m_renderer.m_width / 4, m_renderer.m_height / 4);

	return true;
}

void ExampleScene::Update() {
	m_time.Tick();
	m_input.Update();

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			m_quit = true;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
			m_quit = true;
		}
	}
}

void ExampleScene::Draw() {
	m_framebuffer->Clear(color_t{ 0, 0, 0, 255 });

	for (int i = 0; i < 1000; i++) {
		int rand1 = random(0, m_renderer.m_width / 4);
		int rand2 = random(0, m_renderer.m_height / 4);
		int rand3 = random(0, 255);
		int rand4 = random(0, 255);
		int rand5 = random(0, 255);
		m_framebuffer->DrawPoint(rand1, rand2, color_t{ (uint8_t)rand3, (uint8_t)rand4, (uint8_t)rand5, 255 });
	}

	// update framebuffer
	m_framebuffer->Update();

	// show screen
	m_renderer = *m_framebuffer;
	SDL_RenderPresent(m_renderer.m_renderer);
}