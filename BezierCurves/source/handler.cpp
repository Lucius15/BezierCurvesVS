#include "pch.h"

#include "handler.h"

#include "calc.h"
#include "render.h"

void error(int error, const char* description)
{
	cerr << error << " : " << description << "\n";
}

void reshape(GLFWwindow* window, int w, int h)
{
	width = w;
	height = h;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(viewx, width + viewx, height + viewy, viewy, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void renderGraphics()
{
	if (isRenderGrid)
		renderGrid(100);

	if(isRenderBase)
		renderBezierBase();

	if (isCalculateBezier)
		calculateBezierCurve();

	if (bezierType == 1 && isRenderSubbezier && !basepoints.empty())
	{
		calculateBezierPoint(subbezierT, -1, 0);

		renderSubbezier();
	}

	renderBezierCurve();
}

void mouse(GLFWwindow* window, int button, int action, int mode)
{
	double x, y;
	glfwGetCursorPos(window, &x, &y);
	x += viewx;
	y += viewy;

	ImGuiIO& io = ImGui::GetIO();
	if (!io.WantCaptureMouse && action == GLFW_PRESS)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{
			auto point_on_click = findPointOnClickPos((int)x, (int)y, base_radius);

			if (movingpoint != basepoints.end())
			{
				movingpoint->first = (int)x;
				movingpoint->second = (int)y;

				movingpoint = basepoints.end();

				isCalculateBezier = true;

				return;
			}

			if (point_on_click == basepoints.end())
			{
				basepoints.push_back({ (int)x, (int)y });

				movingpoint = basepoints.end();

				isCalculateBezier = true;
			}
			else
				movingpoint = point_on_click;
		}
		else if (button == GLFW_MOUSE_BUTTON_RIGHT)
		{
			auto point_on_click = findPointOnClickPos((int)x, (int)y, base_radius);
			if (point_on_click != basepoints.end())
			{
				basepoints.erase(point_on_click);

				movingpoint = basepoints.end();

				isCalculateBezier = true;
			}
		}
	}
}

void keyboard(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	ImGuiIO& io = ImGui::GetIO();
	if (io.WantCaptureKeyboard)
		return;

	switch (key)
	{

	case GLFW_KEY_UP:
		viewy = (viewy - step_size >= -height * max_field ? viewy - step_size : -height * max_field);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(viewx, width + viewx, height + viewy, viewy, -1, 1);

		break;

	case GLFW_KEY_DOWN:
		viewy = (viewy + step_size <= height * max_field-height ? viewy + step_size : height * max_field-height);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(viewx, width + viewx, height + viewy, viewy, -1, 1);

		break;

	case GLFW_KEY_RIGHT:
		viewx = (viewx + step_size <= width * max_field-width ? viewx + step_size : width * max_field-width);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(viewx, width + viewx, height + viewy, viewy, -1, 1);

		break;

	case GLFW_KEY_LEFT:
		viewx = (viewx - step_size >= -width * max_field ? viewx - step_size : -width * max_field);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(viewx, width + viewx, height + viewy, viewy, -1, 1);

		break;
	}
}
