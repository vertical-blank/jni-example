package vblank;

public class HelloJni {

    public static void main(String[] args) {
        System.loadLibrary("vblank_Native");

        System.out.println(Native.calc(1, 8));
    }

    public static void fromC() {
        System.out.println(Native.calc(1, 8));
    }

}

