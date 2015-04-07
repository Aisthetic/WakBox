#include "AuthDatabase.h"

void AuthDatabase::LoadQueries()
{
    LoadQuery(SELECT_ACCOUNT_BY_USERNAME, "SELECT * FROM accounts WHERE username = ?");
    LoadQuery(SELECT_ACCOUNT_BY_TOKEN, "SELECT * FROM accounts WHERE session_token = ?");

    LoadQuery(SELECT_REALMS, "SELECT * FROM realm ORDER BY id DESC");
    LoadQuery(SELECT_REALM_CONFIGURATION, "SELECT * FROM realm_conf WHERE realm_id = ? ORDER BY id DESC");

    LoadQuery(UPDATE_SESSION_TOKEN, "UPDATE account SET session_token = ? WHERE id = ?");
}
