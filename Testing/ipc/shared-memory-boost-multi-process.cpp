/**
 * Testing that shared memory with boost works with multiple processes
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
    shared_memory_object::remove(shm_name.c_str());

    // Make sure we've removed this shared memory region by trying to open it (throws)
    // Note that it's cleared on reboot since it has kernel persistence
    shared_memory_object shm_obj2(open_only, shm_name.c_str(), read_write);


    return 0;
}