/// examples of control structures and general flow of control
pub fn run_examples() {
    use std::thread;

    //// simple thread
    // create new thread. it starts running immediately, but join() is 
    // necessary to make sure it completes, as the main thread will
    // terminate earlier without it.
    // uncomment to see it work!
    /*thread::spawn(|| {
        for i in 0..10 {
            println!("{:?}: counted to {}", thread::current().id(), i);
            thread::sleep(std::time::Duration::from_millis(200));
        }
    }).join().unwrap();*/

    //// using mutexes
    use std::sync::{Arc, Mutex};
    // normal vector
    let vector = vec![0u8];
    // wrap with mutex and arc (to enable thread-safe multiple ownership)
    let mutex: Arc<Mutex<Vec<u8>>> = Arc::new(Mutex::new(vector));

    // spawn 10 threads and let them push a random number to vector each
    let mut handles = vec![];
    for _ in 0..9 {

        // create a clone of the arc (and contained mutex) that can be moved to the new thread
        let mutex = Arc::clone(&mutex);

        // spawn new thread
        let handle = thread::spawn(move || {

            // lock mutex and get guarded value
            let mut vector = mutex.lock().unwrap();
            // push random u8 to vector
            use rand::Rng;
            let number: u8 = rand::thread_rng().gen();
            vector.push(number);

            // unlocking happens automatically! :o

        });

        // save handle to join on it later
        handles.push(handle);
    }

    // wait for all threads to terminate
    for handle in handles {
        handle.join().unwrap();
    }

    // lock vector in the main thread
    let vector = mutex.lock().unwrap();
    assert_eq!(vector.len(), 10); // => it worked!
    //println!("{:?}", vector);
}