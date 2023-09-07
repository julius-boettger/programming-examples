/// examples for collections, see https://doc.rust-lang.org/std/collections
/// VecDeque, LinkedList, HashMap, BTreeMap, HashSet, BTreeSet, BinaryHeap
pub fn run_examples() {

    use std::collections::{
        VecDeque,
        LinkedList,
        HashMap,
        BTreeMap,
        HashSet,
        BTreeSet,
        BinaryHeap
    };

    //// Vec (already covered in basics.rs)
    let mut vec: Vec<i32> = Vec::new();
    vec.insert(0, 0);
    vec.push(0);

    //// VecDeque
    let mut vecdeque: VecDeque<i32> = VecDeque::new();
    vecdeque.insert(0, 0);
    vecdeque.push_front(1);
    vecdeque.push_back(2);
    vecdeque.pop_front();

    //// LinkedList
    let mut linkedlist: LinkedList<i32> = LinkedList::new();
    linkedlist.push_front(1);
    linkedlist.push_back(2);
    linkedlist.pop_front();

    //// HashMap
    let mut hashmap: HashMap<String, i32> = HashMap::new();
    hashmap.insert(       "cool number".to_owned(), 12);
    hashmap.insert("pretty cool number".to_owned(),  0);

    //// BTreeMap
    let mut btreemap: BTreeMap<String, i32> = BTreeMap::new();
    btreemap.insert(       "cool number".to_owned(), 12);
    btreemap.insert("pretty cool number".to_owned(),  0);

    //// HashSet
    let mut hashset: HashSet<i32> = HashSet::new();
    hashset.insert(0);

    //// BTreeSet
    let mut btreeset: BTreeSet<i32> = BTreeSet::new();
    btreeset.insert(0);

    //// BinaryHeap
    let mut binaryheap: BinaryHeap<i32> = BinaryHeap::new();
    binaryheap.push(0);

}