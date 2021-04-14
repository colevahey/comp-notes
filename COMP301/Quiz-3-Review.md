## Design Patterns

### Iterator (a05-Driver)
**What problem does this design pattern address?**  
Iterators provide a way to access the elements of an
aggregate object sequentially without exposing its
underlying representation.

**Steps:**  
```Java
Iterator<E> // Encapsulate collection with Iterator object
Iterable<E> // OR call iterator() method on iterable class

if (i.hasNext()) {
  Type next = i.next(); // throws NoSuchElementException if hasNext is false
}
```

**Benefits:**  
You can use iterators for any Collection class  
If you are using a for loop, you can't update the
Collection. You can easily update the collection with an
iterator  
The method names are simple and easy to use (universal)  

**Enhanced For Loop**  
```Java
List<String> fruit = new ArrayList<>();
fruit.add("Apple");
fruit.add("Banana");

// for-loop
for (int i = 0; i < fruit.size(); i++) {
  System.out.println(fruit.get(i));
}

// for-each loop
for (String current : fruits) {
  System.out.println(current);
} 
```

### Decorator (a06-PictureImage)
**What problem does this design pattern address?**  
Instead of implementing functionality directly, methods
*delegate* to the encapsulated instance  

**Steps:**  
```Java
public interface Image {
  // ...

  public void sayHi();
}

public class BaseImage implements Image {

  // ...

  public void sayHi() {
    System.out.println("hi");
  }
}

public class BorderImage implements Image {
  private final Image baseImage;

  public BorderImage(Image baseImage) {
    this.baseImage = baseImage;
  }

  public void sayHi() {
    baseImage.sayHi();
  }
}
```

**Benefits:**  
Allows behavior to be added to an individual object without
affecting the behavior of other objects from the same class  
Extends the functionality of a certain object statically or
at some cases at run-time independently of other instances
of the same class  

### Singleton/Multiton (a07-Pizza)
**What problem does this design pattern address?**  
Singleton - Restricts instantiation of a class to one single
instance  
Multiton - Similar idea to singleton, but we store
a collection of static instances  

**Singleton Steps:**  
```Java
public class FontCamera implements Camera {
  // Static singleton
  private static FrontCamera singleton;

  // Private constructor
  private FrontCamera() {
    // Constructor
  }

  // Static create
  public static FrontCamera create() {
    // Lazy initialization
    if (singleton == null) {
      singleton = new FrontCamera();
    }
    return singleton;
  }
}
```

**Multiton Steps:**  
```Java
public class Resource {
  private static Resource[] resources;
  private static int index;

  private Resource() {
    // Constructor
  }

  public static Resource acquire() {
    if (resources == null) {
      resources = new Resource[] {
        new Resource(),
        new Resource(),
        new Resource()
      };
    }
    index = (index + 1) % 3;
    return resources[index];
  }
}
```

**Benefits:**  
*Compared to global variables:*  
Singleton instance field don't take up space in global
namespace  
Singletons may be lazily initialized  
*Compared to static classes:*  
Singletons can implement interfaces  
Singletons can be passed as parameters  
Singletons can have their instances swapped out  

### Factory Method (a07-Pizza)
**What problem does this design pattern address?**  
A factory method is a static method whose job is to create
and return a new instance of the class and more importantly,
to dynamically select which type of subclass to instantiate  

**Steps:**  
```Java
class TNotification extends Notification {...};
class ENotification extends Notification {...};

public class Notification {
  public enum Type { TEXT, EMAIL };

  public static Notification create(Type nType) {
    if (nType = Type.TEXT) {
      return new TNotification();
    } else if (nType = Type.EMAIL) {
      return new EmailNotification();
    } else {
      throw new UnsupportedOperationException();
    }
  }
}
```

**ABSTRACT FACTORY**  
Move factory method into its own class  
Further isolates the process of instantiation  
```Java
public class NotificationFactory {
  public static Notification create(Type nType) {
    if (nType = Type.TEXT) {
      return new TNotification();
    } else if (nType = Type.EMAIL) {
      return new EmailNotification();
    } else {
      throw new UnsupportedOperationException();
    }
  }
}
```

**Benefits:**  
The object you create can be used without code duplication  
If you use a factory method instead of a constructor, the
factory method can have different and more descriptive names  
It removes instantiation of the implementation classes from
the client node  
Makes the code more robust, less coupled, easy to expand  
Factory pattern through inheritance provides abstraction
between implementation and the client classes  

### Observer (a08-Store)
**What problem does this design pattern address?**  
Acts as the building block of MVC pattern for UI
development. It should be ensured that when 1 object changes
state, an open-ended number of dependent objects are updated
automatically  

**Steps:**  
```Java
public class Button {
  private List<Observer> observers;

  public Button() {
    // ...
  }

  public void addObserver(Observer o) {
    observers.add(o);
  }

  public void removeObserver(Observer o) {
    observers.remove(o);
  }

  public void notify() {
    for (Observer o : observers) {
      o.update(this);
    }
  }
}

public class ButtonObserver implements Observer {
  public void update(Button b) {
    System.out.println("Button was pressed: " + b);
  }
}
```
*Subject* -> `addObserver()`;`removeObserver()`;`notify()`  
*Observer* -> `update()`  

**Benefits:**  
Supports the principle of loose coupling between objects
that interact with each other  
Allows sending data to other objects effectively without any
change in the Subject or Observer classes  
Observers can be added/removed at any point in time  
