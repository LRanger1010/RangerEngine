#pragma once
#include "pch.h"
#include "IEventListener.h"

namespace Ranger
{
	class EventDispatcher
	{
	public:
		EventDispatcher();
		~EventDispatcher();

		virtual void AddEventListener(const unsigned int eventId, std::function<void()> callback)
		{
			if (m_listenerMap.find(eventId) == m_listenerMap.end())
			{
				std::vector<std::function<void()>> listeners;
				listeners.push_back(callback);
				m_listenerMap.insert({ eventId, listeners });
			}
			else
			{
				auto listeners = m_listenerMap[eventId];
				listeners.push_back(callback);
			}
		}

		virtual void DispatchEvent(const unsigned int eventId)
		{
			if (m_listenerMap.find(eventId) != m_listenerMap.end())
			{
				auto listeners = m_listenerMap[eventId];
				for (auto& listener: listeners)
				{
					listener();
				}
			}
		}

	private:
		std::unordered_map<unsigned int, std::vector<std::function<void()>>> m_listenerMap;
	};
}