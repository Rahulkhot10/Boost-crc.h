
#include <boost/crc.hpp>      // for boost::crc_basic, boost::augmented_crc
#include <boost/cstdint.hpp>  // for boost::uint16_t
#include <cassert>    // for assert
#include <iostream>   // for std::cout
#include <ostream>    // for std::endl

using namespace std;
using namespace boost;
// Main function
int main (){
    //using boost::uint16_t;
    //using boost::augmented_crc;
    int n;
    cout<<"enter size of array:"<<endl;
    cin>>n;

    uint32_t data[n] = { };

    for(int i=0;i<sizeof(data);i++){
        cin>>data[i];
    }
    
    // uint16_t const  init_rem = 0x123;
    ///uint16_t  crc1 = augmented_crc<16, 0x8005>( data, sizeof(data), init_rem );
    // uint16_t const  zero = 0;
    // uint16_t const  new_init_rem = augmented_crc<16, 0x8005>( &zero, sizeof(zero) );

    crc_basic<16>  crc2(0x8005);
    cout<<"sizeOfData:"<<sizeof(data)<<endl;
    crc2.process_bytes(data,sizeof(data));  // don't include CRC
    cout<<"Checksum <basic<16>>: "<<crc2.checksum()<<endl;
    
    crc_16_type crc3(0x8005);
    cout<<"sizeOfData:"<<sizeof(data)<<endl;
    crc3.process_bytes(data,sizeof(data));
    cout<<"Checksum <crc_16_type>: "<<crc3.checksum()<<endl;

    crc_32_type crc4(0x04C11DB7);
    cout<<"sizeOfData <crc_32_type>:"<<sizeof(data)<<endl;
    crc4.process_bytes(data,sizeof(data));
    cout<<"Checksum <crc_32_type>: "<<crc4.checksum()<<endl;
    return 0;
}





















