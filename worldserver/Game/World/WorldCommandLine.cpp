#include "WorldCommandLine.h"

void WorldCommandLine::HandleCommand(QString command)
{
    Chat::Instance()->ParseCommand(command);
}
