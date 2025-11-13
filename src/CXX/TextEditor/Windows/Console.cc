#include <span>
#include <TUI.h>

EXPORT_FUNCTION TUIResult
TUI_GetConsoleEvents(TUIConsole* pConsole,
					 TUIConsoleEventProperties* pEvents,
					 size_t* pEventCount)
{


	//> Get console user input
	int input = 0;
	int event_count = 0;

	while ((ch = getc(stdin)) != EOF) {
		event_count++;
			
		if (event_count > 255) {
			// Disregard old events
			event_count = 0;
		}
			
		auto& event = *events[event_count];
		event.eventType = TUI_EVENT_USER_INPUT;
		event.userInputValue = input;
	}
	
	*pEventCount = event_count;
	return TUI_SUCCESS;
	
}// end TUI_GetConsoleEvents

TUI_RESULT TUI_RenderConsole(TUIConsole* pConsole) {
	std::span<TUIFrame> frame_list(console->frames, console->size);

	for(const auto& frame : frame_list) {
		
	}
	return TUI_SUCCESS;
}
