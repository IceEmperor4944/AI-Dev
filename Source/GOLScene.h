#pragma once
#include "Scene.h"
#include "Framebuffer.h"
#include "Cells.h"
#include <memory>

class GOLScene : public Scene {
public:
	bool Initialize() override;
	void Update() override;
	void Draw() override;

public:
	std::unique_ptr<Framebuffer> m_framebuffer;
	std::unique_ptr<Cells<uint8_t>> m_cellsA;
	std::unique_ptr<Cells<uint8_t>> m_cellsB;

	int m_frame = 0;
};