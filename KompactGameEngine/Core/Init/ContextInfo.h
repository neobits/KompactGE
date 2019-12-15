#pragma once

namespace Core
{
	/* OpenGL versions */
	struct ContextInfo
	{
		int majorVersion, minorVersion;
		bool isCore;

		ContextInfo()
		{
			majorVersion = 3;
			minorVersion = 3;
			isCore = true;
		}

		ContextInfo(int major_version, int minor_version, bool use_core)
		{
			this->majorVersion = major_version;
			this->minorVersion = minor_version;
			this->isCore = use_core;
		}

		/* Copy constructor */
		ContextInfo(const ContextInfo& contextInfo)
		{
			this->majorVersion = contextInfo.majorVersion;
			this->minorVersion = contextInfo.minorVersion;
			this->isCore = contextInfo.isCore;
		}

		void operator=(const ContextInfo& contextInfo)
		{
			majorVersion = contextInfo.majorVersion;
			minorVersion = contextInfo.minorVersion;
			isCore = contextInfo.isCore;
		}
	};
}