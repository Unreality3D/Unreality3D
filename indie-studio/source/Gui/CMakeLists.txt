cmake_minimum_required (VERSION 2.8)

project (Gui)

set(GUI-DIR "${CMAKE_SOURCE_DIR}/source/Gui")

set(GUI-SRC
	"${GUI-DIR}/System.cpp"
	"${GUI-DIR}/Manager.cpp"
	"${GUI-DIR}/TextRegistrar.cpp"
	"${GUI-DIR}/AComponent.cpp"
	"${GUI-DIR}/Context.cpp"
	"${GUI-DIR}/Palette.cpp"
	"${GUI-DIR}/SampleButton.cpp"
	"${GUI-DIR}/SampleContext.cpp"
	"${GUI-DIR}/Helper.cpp"
	"${GUI-DIR}/MainMenuContext.cpp"
	"${GUI-DIR}/MenuButton.cpp"
	"${GUI-DIR}/DebugContext.cpp"
	"${GUI-DIR}/DebugText.cpp"
	"${GUI-DIR}/Toggler.cpp"
	"${GUI-DIR}/FunctorButton.cpp"
	"${GUI-DIR}/Callbacks.cpp"
	"${GUI-DIR}/EscMenuContext.cpp"
	"${GUI-DIR}/InputField.cpp"
	"${GUI-DIR}/FunctorField.cpp"
	"${GUI-DIR}/ClassSelectContext.cpp"
	"${GUI-DIR}/NetContext.cpp"
	"${GUI-DIR}/LifeBar.cpp"
	"${GUI-DIR}/SampleText.cpp"
	)

add_library(Gui SHARED ${GUI-SRC})

target_link_libraries(Gui
                        -lOgreMain
                        -lboost_system
			-lOgreOverlay
                        )
