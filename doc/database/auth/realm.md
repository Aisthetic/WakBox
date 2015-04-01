# realm

## Columns

### `realm_id`
+ type : `int`
+ comment : reference of table [realm] (https://github.com/KevinSupertramp/WakBox/blob/master/doc/realm/realm.md)

### `name` 
+ type : `varchar(32)`
+ comment : Name of the realm
    
### `address` 
+ type : `varchar(20)`
+ comment : IP address of the realm (WorldServer)
+ default : 127.0.0.1 (localhost)

### `port` 
+ type : `smallint(5)`
+ comment : Realm's port (WorldServer)
+ default : 5556

### `version` 
+ type : `varchar(10)`
+ comment : Realm's version
+ default : 1.39.4

### `community` 
+ type : `tinyint(3)`
+ comment : Community ID
+ default : 0 (FR)

### `player_count` 
+ type : `int(10)`
+ comment : Total characters created on this realm

### `player_limit` 
+ type : `int(10)`
+ comment : Limit total characters on the realm

### `security_access_level` 
+ type : `tinityint(3)`
+ comment : Minimum gm_level to access the realm

### `locked` 
+ type : `tinyint(3)`
+ comment : Lock access to the realm (bool 0 = unlocked, 1 = locked)
+ default : 0 (unlocked)
