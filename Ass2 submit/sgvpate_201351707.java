// Student Name : Viraj Patel
// Student ID   : 201351707

//NOTE : code did not return expected output. stuggled to implement a loop with the shelf size to limit the shelf size to 5
// 
class Buffer { 

    private int shelf;  // creating the data structure to store the data
    private volatile boolean empty = true; // initialliaing the shelf will be empty

    
    public synchronized void insert(int item){ // using synchronised so all threads can access this method
        while (!empty){
            System.out.println("Waiting to add insert..."); // if the shelf is full, we wait untill we can add to it
            try {
                wait();
            } catch(InterruptedException e) {}
        }
        empty = false;
        shelf = item;
        notify();
    }
    
    public synchronized int remove(){ // using synchronised so all threadscan access this method
        while (empty){ 
            System.out.println("Charlie is Waiting to pack..."); // if shelf is empty , we wait untill there is something to remove
            try{
                wait();
            } catch(InterruptedException e) {}
        }
        empty = true;
        notify();
        return shelf;
    }
}
    
/////////////////////////////////////////////////////////////////////////////////////////////////

class PotterA extends Thread { // creating a new thread
    
    private Buffer buff;
    
    public PotterA(Buffer b){
        buff = b;
    }
    public void run(){
        System.out.println("Alpha is making a pot.");
        try {
            sleep(500);  // implementig the wait method that was provided
        } catch(InterruptedException e) {}
        buff.insert(1);
        System.out.println("Alpha has put 1 pot on the shelf");
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
 
class PotterB extends Thread { // creating a new thread for the second potter
    
    private Buffer buff;
    
    public PotterB(Buffer b){
        buff = b;
    }
    
    public void run(){
        System.out.println("Bravo is making a pot.");
        try {
            sleep(600);
        } catch(InterruptedException e) {}
        buff.insert(1);
        System.out.println("Bravo has put 1 pot on the shelf");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
 
class Packer extends Thread{ // creating a new thread for the packer
    
    private Buffer buff;
    
    public Packer(Buffer b) {
        buff = b ;
        
    }
    public void run() {
        try{
            sleep(400);
        }
         catch(InterruptedException e){}
        
        int removed = buff.remove();
        System.out.println("Charlie has packed one pot");
    }
    
}
   
///////////////////////////////////////////////////////////////////////////////////////////////

public class sgvpate_201351707 {
    
    public static void main(String args[]){
        System.out.println("Alpha has Started");
        System.out.println("Bravo has Started");
        System.out.println("Charlie has Started");
        
        Buffer shelf = new Buffer(); 
        PotterA potA = new PotterA(shelf); // initialising the threads
        PotterB potB = new PotterB(shelf);
        Packer pack = new Packer(shelf);
        
        potA.start(); // starting all of the threads
        potB.start();
        pack.start();
        
        
    }
}
    
    
