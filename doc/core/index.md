# Core

# Naming Convention

## Variables
+ Singleton variable start by `s` **like sWorld**
+ Always set attribute in private and starting by `m_`

## Classes
+ Manager class end by `Mgr`
+ Create getter and setter for read and modify attribute
+ Don't forget to delete all pointer not used anymore
+ Don't call Mgr class in Business Object, only manipulate Businness Object

#Data encapsulation - Code Organisation

In agreement with the *Layered model* (we don't have a DAL - all is in Manager), Wakbox try to be organised like this :

<h1>
<img alt="DataModel" src="https://raw.github.com/KevinSupertramp/WakBox/master/doc/img/datamodel.png" title="DataModel"/>
</h1>

+ DataAccess Object provide Database Access (Databases class in Wakbox)
+ Manager Object provide Buisiness Logic (Create Buisiness Object)
+ Buisiness Object provide Buisiness Manipulation, value validation etc...

+ **DON'T**
  + **SQL Request** in Business Object - use DataAccess Object
  + **toSometing()** in Business Object - use Manager Object
  + **Relation for Buisiness Object**
    + 1-1 Business Object have attributes to get the relation (pointer)
    + 1-n Child Business Object have property to get the parent - Parent Business Object have a list of child
    + n-n Child Business Object have property to get list of child - Parent Business Object have a list of child
  + **Save linked Business Object in Business Object Manager**  - Create a new Manager
    
+ **Why you should do that ?**
  + Change became easier
  + Code portabilty, Object can be copy/paste in another project
