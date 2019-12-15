#pragma once
namespace Core
{
	class IListener
	{
	public:
		virtual ~IListener() = 0;

		// Pure abstract virtual functions (notifiers), i.e. method() = 0
		inline virtual void notifyBeginFrame() = 0;
		inline virtual void notifyDisplayFrame() = 0;
		inline virtual void notifyEndFrame() = 0;
		inline virtual void notifyReshape(int width, int height,
										  int prev_w, int prev_h) = 0;
	};

	inline IListener::~IListener(){}
}