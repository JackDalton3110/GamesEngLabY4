public class ProducerConsumerTest {
   public static void main(String[] args) {
      Buffer b = new Buffer();
      Producer p1 = new Producer(b, 1);
      Consumer c1 = new Consumer(b, 1);
      p1.start(); 
      c1.start();
   }
}
class Buffer {
   private int contents;
   private boolean available = false;
   
   public synchronized int get() {
      while (available == false) {
         try {
            wait();
         } catch (InterruptedException e) {}
      }
      available = false;
      notifyAll();
      return contents;
   }
   public synchronized void put(int value) {
      while (available == true) {
         try {
            wait();
         } catch (InterruptedException e) { } 
      }
      contents = value;
      available = true;
      notifyAll();
   }
}
class Consumer extends Thread {
   private Buffer m_buffer;
   private int number;
   
   public Consumer(Buffer b, int number) {
      m_buffer = b;
      this.number = number;
   }
   public void run() {
      int value = 0;
      for (int i = 0; i < 20; i++) {
         value = m_buffer.get();
         System.out.println("Consumer #" + this.number + " got: " + value);
      }
   }
}
class Producer extends Thread {
   private Buffer m_buffer;
   private int number;
   public Producer(Buffer b, int number) {
      m_buffer = b;
      this.number = number;
   } 
   public void run() {
      for (int i = 0; i < 20; i++) {
         m_buffer.put(i);
         System.out.println("Producer #" + this.number + " put: " + i);
         try {
            sleep((int)(Math.random() * 100));
         } catch (InterruptedException e) { }
      } 
   }
}