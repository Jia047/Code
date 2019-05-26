public class NotInitialization{
    public static void main(String[] args){
        // 输出：SuperClass init
        //      123
        // System.out.println(SubClass.value);

        // 没有任何输出
        // SuperClass[] sca = new SuperClass[10];

        // 输出 hello world
        // 并没有输出 ConstClass init
        System.out.println(ConstClass.HELLO_WORLD);
    }
}
