# OnPlayerTurnUpsideDown

* Name:
  OnPlayerTurnUpsideDown
* Type:
  Gameplay hack
* Description:
  This modification alters player rotation quaternions, making the user look upside down to other players.
* Detection Method:
  This include converts the player rotation quaternions to Euler Angles (y axis) and checks if it's above 85.0 or below -85.0, values which you won't get legitely. This method will also detect parkour mods or any other modification that turns the player upside down.
* Callback:
  OnAntiCheatTurnUpsideDown(playerid, Float:angle)
* Author:
  Jelly23

## Installation

Simply install to your project:

```bash
sampctl package install samp-anti-cheat/OnPlayerTurnUpsideDown
```

Include in your code and begin using the library:

```pawn
#include <optud>
```

## Testing

To test, simply run the package:

```bash
sampctl package run
```

And connect to `localhost:7777` to test - calls to `OnPlayerTurnUpsideDown` are logged to the console.
