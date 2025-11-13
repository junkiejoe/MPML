#pragma once
#ifndef _TUI_H
#define _TUI_H

#include <stdint.h>

#define EXPORT_FUNCTION
#define TUI_HANDLE(object) typedef struct object##_T* object;

#define MakeError()
#define MakeWarning()
#define TUI_IsError(num)

enum TUIResultEnum {
	TUI_SUCCESS = 0,
};

typedef enum TUIConsoleEvent {
	TUI_EVENT_NONE = 0,
	TUI_EVENT_USER_INPUT = 1,
} TUIConsoleEvent;

#undef MakeError
#undef MakeWarning

typedef uint32_t TUIResult;

//------------------
// Handles
//------------------



//------------------
// Structures
//------------------

// Structure describing the scale and offset of a 2D element.
typedef struct TUIUDim2 {
	int32_t x, y;
	float sx, sy;
} TUIUDim2;

// Structure containing the properties of the platform's console window.
typedef struct TUIConsole {
	int width, height;
	// Raw list of display characters to be displayed onto the console.
	size_t* displayCharacters;
	TUIFrame* frames;
	size_t frameCount;
} TUIConsole;

typedef struct TUIFrame {
	int width, height;
	TUIUDim2 position;
	TUIUDim2 scale;
	// Raw list of display characters to be displayed onto the console.
	size_t* displayCharacters;
} TUIFrame;

typedef struct TUIConsoleEventProperties {
	// The TUIConsoleEvent of the event
	int eventType;
	int userInputValue;
};

//----------------
// Functions
//----------------
EXPORT_FUNCTION TUIResult
TUI_GetConsoleEvents(TUIConsole* console,
					 TUIConsoleEventProperties* event,
					 size_t eventCount);
EXPORT_FUNCTION TUIResult TUI_RenderConsole(TUIConsole* console);
EXPORT_FUNCTION TUIResult TUI_NewFrame(TUIUDim2 udim);

#undef EXPORT_FUNCTION
#endif// _TUI_H
