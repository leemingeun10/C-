#include "Player.h"
#include"UInput.h"
#include"Vector2D.h"
APlayer::APlayer()
{
	Shape = 'P';
	Location.x = 1; 
	Location.y = 1;
}

void APlayer::Tick()
{
	switch (UInput::KeyCode)
	{
	case 'w':
		AddActorWorldOffset(FVector2D( 0, - 1 ));
		break;
	case 's':
		AddActorWorldOffset(FVector2D(0,1));
		break;
	case 'a':

		AddActorWorldOffset(FVector2D(1, -0));
		break;
	case 'd':
		AddActorWorldOffset(FVector2D(-1, 0));
		break;



	}
}
