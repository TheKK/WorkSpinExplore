/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: logLocator.h
 */

#ifndef LOG_LOCATOR_H
#define LOG_LOCATOR_H

#include "log.h"
#include "nullLog.h"

class LogLocator
{
	public:
		static void Init();
		static Log* GetService();
		static void Register(Log* service);
	private:
		static Log* service_;
		static NullLog nullService_;
};

#endif	/* LOG_LOCATOR_H */
