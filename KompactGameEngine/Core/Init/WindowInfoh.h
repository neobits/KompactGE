#pragma once
#include<string>

namespace Core
{
	struct WindowInfo
	{
		std::string name;
		int width;
		int height;
		int position_x;
		int position_y;
		bool isReshapable;

		WindowInfo()
		{
			name = "OpenGL Window";
			width = 800; height = 600;
			position_x = 300;
			position_y = 300;
			isReshapable = true;
		}

		WindowInfo(std::string name, int pos_x, int pos_y,
			int width, int height, bool reshape_window)
		{
			this->name = name;
			this->position_x = pos_x;
			this->position_y = pos_y;
			this->width = width;
			this->height = height;
			this->isReshapable = reshape_window;
		}

		/* Copy constructor */
		WindowInfo(const WindowInfo& windowInfo)
		{
			this->name = windowInfo.name;
			this->position_x = windowInfo.position_x;
			this->position_y = windowInfo.position_y;

			this->width = windowInfo.width;
			this->height = windowInfo.height;
			this->isReshapable = windowInfo.isReshapable;
		}

		void operator=(const WindowInfo& windowInfo)
		{
			name = windowInfo.name;
			position_x = windowInfo.position_x;
			position_y = windowInfo.position_y;

			width = windowInfo.width;
			height = windowInfo.height;
			isReshapable = windowInfo.isReshapable;
		}
	};
}