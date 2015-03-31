# realm_info

## Columns

### `realm_id`
+ type : `int`
+ comment : reference of table [realm] (https://github.com/KevinSupertramp/WakBox/blob/master/doc/realm/realm.md)

### `system_configuration_id` 

+ type : `int`
+ comment : available value on **SystemConfiguration.h** - *take care of value type*
    
### `value` 
+ type : `varchar` 
+ comment : text value of the params
 + `BOOLEAN` value accept `true` and  `false`
 + `NUMBER` value accept `integer`
 + `STRING` value accept `string`
 + `STRINGLIST`value accept `string`separate by `;`
 + `NUMBERLIST`value accept `int` separate by `;`
