#pragma once
class Scene
{
public:
	virtual void Initialize() = 0;

	virtual void Update() = 0;

	virtual void Release() = 0;
};