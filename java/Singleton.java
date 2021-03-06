// 饿汉式：在类加载的时候便实例化一个对象
public class Singleton{
    private static Singleton instance = new Singleton();

    private Singleton(){

    }
    public static Singleton getInstance(){
        return instance;
    }
}

// 懒汉式：在第一次需要该对象时再进行实例化
// 这种方式需要注意在高并发时的并发控制
public class Singleton{
    private static Singleton instance;

    private Singleton(){

    }
    // 该方法是同步方法，每次获取实例都要获得锁释放锁，影响性能
    public static synchronized Singleton getInstance(){
        if(instance == null){
            instance = new Singleton();
        }

        return instance;
    }
}

// 懒汉式（双重检验加锁版本）
public class Singleton {
    // volatile 关键字可以防止虚拟机的指令重排序，保证对象的可见性
    // 关于重排序，这里用实例化的过程来说明
    // 对于 instance 的实例化，包含一下三个步骤
    // 1. 为对象开辟内存空间
    // 2. 将对象初始化
    // 3. 将 instance 指向该内存空间
    // 因为存在指令重排序，所以执行的步骤可能是 1-2-3 或者 1-3-2，
    // 如果是 1-3-2,在高并发的情况下实例化对象，可能会导致线程A执行了 1-3 这时候，
    // 线程B来获取实例，发现 instance ！= null，于是直接使用，但是此时 instance
    // 引用的空间是没有初始化的，由此会导致程序报错
    private volatile static Singleton instance;

    private Singleton() {

    }

    public static Singleton getInstance() {
        if(instance == null){
            // 只有在第一次才会走完全部流程
            synchronized(Singleton.class){
                // 再次判断，可能有其他线程已经在本线程获得所之前实例化了 instance
                if(instance == null){
                    instance = new Singleton();
                }
            }
        }
        return instance;
    }
}

// 静态内部类方式
// 在加载外部类时，如果没有相关调用到内部类，那么内部类是不会参与加载的
// 这种方式不仅具有延迟初始化的好处，同时由JVM 提供了对线程安全的支持
public class Singleton {
    private Singleton() {

    }

    private satic class SingletonHolder {
        private static final Singleton INSTANCE = new Singleton();
    }

    // 执行该方法时，SingletonHolder 才会被加载
    public static getInstance() {
        return SingletonHolder.INSTANCE;
    }
}

// 枚举方式
// 在其它实现中，通过 setAccessible() 方法可以将私有构造函数
// 的访问级别设置为 public，然后调用构造函数从而实例化对象，如果
// 要防止这种攻击，需要在构造函数中添加防止多次实例化的代码。该实现
// 是由 JVM 保证只会实例化一次，因此不会出现上述的反射攻击。
public enum Singleton {
    INSTANCE;

    private String objName;


public String getObjName() {
    return objName;
}


public void setObjName(String objName) {
    this.objName = objName;
}


public static void main(String[] args) {

    // 单例测试
    Singleton firstSingleton = Singleton.INSTANCE;
    firstSingleton.setObjName("firstName");
    System.out.println(firstSingleton.getObjName());
    Singleton secondSingleton = Singleton.INSTANCE;
    secondSingleton.setObjName("secondName");
    System.out.println(firstSingleton.getObjName());
    System.out.println(secondSingleton.getObjName());

    // 反射获取实例测试
    try {
        Singleton[] enumConstants = Singleton.class.getEnumConstants();
        for (Singleton enumConstant : enumConstants) {
            System.out.println(enumConstant.getObjName());
        }
    } catch (Exception e) {
        e.printStackTrace();
    }
}
// 输出为
firstName
secondName
secondName
secondName
}
