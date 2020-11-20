#include "acceleration_structures.h"

#include <chrono>

int main(int argc, char* argv[])
{
	AccelerationStructures* render = new AccelerationStructures(1920, 1080);
	int result = render->LoadGeometry("models/CornellBox-Original.obj");
	if (result)
	{
		return result;
	}
	render->BuildBVH();
	render->SetCamera(float3{ 0.0f, 1.1f, 2 }, float3{ 0, 1, -1 }, float3{ 0, 1, 0 });
	render->AddLight(new Light(float3{ 0, 1.9f, -0.06f }, float3{ 0.78f, 0.78f, 0.78f }));
	render->Clear();
	auto start = std::chrono::high_resolution_clock::now();
	render->DrawScene();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Rendering time: " << diff.count() << " s\n";
	result = render->Save("results/aabb.png");
	return result;
}