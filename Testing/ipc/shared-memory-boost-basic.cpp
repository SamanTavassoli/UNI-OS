/**
 * Testing out shared memory using boost which is said to be extensively used in practice
 * Just writing out the basic stuff here
 * References:
 * https://www.boost.org/doc/libs/1_51_0/doc/html/interprocess/sharedmemorybetweenprocesses.html
 * https://man7.org/linux/man-pages/man7/shm_overview.7.html
 * https://stackoverflow.com/questions/57188832/what-happen-if-fail-to-delete-a-shared-memory-segment
*/

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace boost::interprocess;

int main(int argc, char *argv[]) {

    string shm_name = "shared_memory";
    size_t shm_size = 10000; // Bytes

    // Note that this struct makes it so the remove function is automatically called at the end of exec
    // because the object is destructed, and we also have it when its constructed
    struct shm_remove
      {
         shm_remove() { shared_memory_object::remove("shared_memory"); }
         ~shm_remove(){ shared_memory_object::remove("shared_memory"); }
      } remover;

    // All interactions with the shared memory space (via any process) is done via this object
    shared_memory_object shm_obj(open_or_create, shm_name.c_str(), read_write);
    // Default size is 0 so must truncate
    shm_obj.truncate(shm_size);

    // Must specify how much of the shared memory to map to current process
    mapped_region region(shm_obj, read_write, shm_size/2, shm_size-shm_size/2);
    void* address = region.get_address();
    size_t size = region.get_size();

    cout << "Address of created memory region: " <<  address << endl;
    cout << "Size of created memory region: " <<  size << endl;

    // Must explicitly remove (yes it's a static function)
    // shared_memory_object::remove(shm_name.c_str());
    // Commented out since we have the shm_remove struct above to do that for us

    return 0;
}