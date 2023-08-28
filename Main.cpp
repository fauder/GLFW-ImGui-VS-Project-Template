// Project Includes.
#include "Graphics.h"
#include "ImGuiSetup.h"
#include "Platform.h"

void OnKeyboardEvent( const Platform::KeyCode key_code, const Platform::KeyAction key_action, const Platform::KeyMods key_mods )
{
	if( ImGui::GetIO().WantCaptureKeyboard )
		return;

	switch( key_code )
	{
		/*case Platform::KeyCode::KEY_ESCAPE:
			if( key_action == Platform::KeyAction::PRESS )
				Platform::SetShouldClose( true );
			break;*/
		default:
			break;
	}
}

void DrawImGui()
{
    if( ImGui::Begin( "Test Window" ) )
    {
        ImGui::Text( "Example text." );
    }
}

int main()
{
    Platform::InitializeAndCreateWindow( 800, 600, 100, 100 );
    
    ImGuiSetup::Initialize();

	Platform::SetKeyboardEventCallback(
		[ = ]( const Platform::KeyCode key_code, const Platform::KeyAction key_action, const Platform::KeyMods key_mods )
		{
			OnKeyboardEvent( key_code, key_action, key_mods );
		} );

    /* The render loop. */
    while( !Platform::ShouldClose() )
    {
		Platform::PollEvents();

		GLCALL( glClearColor( 0.55f, 0.55f, 0.55f, 1.0f ) );
		GLCALL( glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ) );

		ImGuiSetup::BeginFrame();

        DrawImGui();

        ImGui::End();

		ImGuiSetup::EndFrame();

        Platform::SwapBuffers();
    }

    ImGuiSetup::Shutdown();

    return 0;
}