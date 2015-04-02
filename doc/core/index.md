# Core

# Naming Convention

+ Singleton variable start by `s` *like sWorld*
+ Always set attribute in private and starting by `m_`
+ Manager class end by `Mgr`

+ Create getter and setter for read and modify attribute
+ Always manipulate object, don't work with raw data
+ Don't forget to delete all pointer not used anymore
+ Take care of Memory Leak

#Data encapsulation

In agreement with the *Layered model* (we don't have a DAL - all is in Manager), your code should be organise like this :

<h1>
<img alt="DataModel" src="https://raw.github.com/KevinSupertramp/WakBox/master/doc/img/datamodel.png" title="DataModel"/>
</h1>

+ Manager provide raw data managing - SQL , JSON and another raw format
+ Object provide Work Logic

+*DON'T*
    + *SQL Request* in Object - Manager handle request
    + *toSometing()* in Object - Manager handle raw data 
    + *getObjectRelation()* in Object - Call the Relation Object Method Example : (Find all Characters for an Account) AccountMgr->getCharacters(Account* Account)
    
+*Why you should do that ?*
    + Change became easier
    + Code portabilty, Object can be copy/paste in another project
    + MgrClass can be modify easier
        
