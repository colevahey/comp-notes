## Quiz 1 Review

#### L1 - Build Automation  
Automate the build process for different programming
languages  
We are using Maven  
Terms to know: POM file, dependency, archetype, artifact,
lifecycle  

#### L1 - Git  
On the heels branch, how do I switch to the heels branch?  
`git checkout heels`  
I want to update my code on github, what do I do?  
`git add .; git commit -m "commit"; git push origin master`  
How do I get updates from github?  
`git pull`

#### L1 - Access Modifiers  
**private** - Member can only be accessed inside the class  
**default** - Member can only be accessed inside the package  
**protected** - Member can only be accessed inside the class
and its subclasses  
**public** - Member can be accessed anywhere  

#### L2 - Anatomy of a Class  
*Instance fields*  
*Class fields*  
*Constructors*  
*Instance methods*  
*Class methods*  
**STATIC KEYWORD MEANS A CLASS MEMBER (method or field)**  
**Anything without static is an instance method**  

#### L2 - Encapsulation Principles  
1. Do not expose the internal state of an object directly
2. Separate exposed behavior from internal behavior  
How would we encapsulate?  
- Mark all instance fields private
- Initialize instance fields in the public constructor
- Use the instance fields in your public methods
- Consider adding getter and setter methods as appropriate
  to expose the raw field values  
Derived getter method helps you use less fields (derive your
fields)  
Setter method validation checks to make sure input values
are valid  

#### L3 - Steps to Inheritance  
- Factor out common code
- Subclasses can use superclass code  

#### L3 - Overriding Methods  
*What is overriding methods?*  
Add `@Override` to use a method differently that was
inherited, if you change in parent, it would change all the
method for all other child classes  
*What problem could I run into?*  
Field access problems - You cannot access a private field,
you will need to use a getter method  

#### L4 - Overloading  
*What can you overload?*  
You can overload methods and constructors  
Constructors can "chain" if they call one another using
`this()`  
*What must be the same for overloading?*  
The same access modifier, the same static/non-static status  
*What needs to be different?*  
The # or types of parameters, and the return type may be
different  

#### L4 - Polymorphism  
Define polymorphism:  
The principle of using one common name or symbol to refer to
multiple different (related) entities  
*Why would we want this?*  
Allows programmers to group different entities together and
treat them with different contexts  

#### L4 - Final Keyword  
*What does the final keyword do?*  
Indicates that a class, member, or variable is immutable  
**Class** - Indicates no subclasses  
**Field** - Field value cannot be changed  
**Method** - Method cannot be overwritten  

#### L4 - This and Super  
*When can you use this?*  
Use it when you are accessing the current object  
ALSO applies to constructor chaining (`this()`)  
*When can you use super?*  
Use it when you are accessing the parent object  
Applies when calling parent constructor (`super()`)  

#### L4 - Extra Questions  
An object *only* has access to the methods associated with
its assigned type  
`prof` cannot access `student` even though they are both
children of `person`  
In Java the overridden method will always be executed,
regardless of the object's assigned type  

#### L4 - Virtual Method Overview  
A method is **virtual** if the overridden version will be
executed regardless of the assigned type  
In Java, **ALL** methods are virtual so the override will
always be executed  

#### L5 - Abstract Classes  
*What does it mean to make a method abstract?*  
It means that a subclass will implement the method  
**Abstract methods do not have a body**  
**If a class has an abstract method it cannot be
instantiated directly**  
*When would I use an abstract method?*  
When it makes sense for every instance to have that method
but there is no good default implementation  

#### L5 - Extra Questions  
*Aggregation* and *Composition* are relationships where one
object encapsulates instances of other objects  
*Aggregation* describes when internal objects can/might
exist independently  on their own  
*Composition* describes when objects only exist together as
a unit  

#### Other Topics - Delegation  
*What is delegation?*  
Delegation is the passing of implementation to somewhere
else  
*Why would you want to use delegation?*  
If a certain class may not have the desired attribute, it
can pass this task to another class which helps with
encapsulation and organization of your code  
Think abstract methods  

#### Composition vs Inheritance  
Classes and objects created through inheritance are *tightly
coupled* because changing the parent or superclass in an
inheritance relationship risks breaking your code  
Classes and objects created through composition are *loosely
coupled* which gives you more flexibility  
For this reason, use composition over inheritance!!!  

