#include <string>
#define DECLARE(TYPE, NAME)   \
    extern TYPE FLAGS_##NAME; 
    
#define DECLARE_bool(NAME) DECLARE(bool, NAME)
#define DECLARE_int32(NAME) DECLARE(int, NAME)
#define DECLARE_int64(NAME) DECLARE(long, NAME)
#define DECLARE_uint64(NAME) DECLARE(unsigned long, NAME)
#define DECLARE_double(NAME) DECLARE(double, NAME)
#define DECLARE_string(NAME) DECLARE(std::string, NAME)

#define DEFINE__(TYPE, NAME, DEFAULT, COMMENT) \
    TYPE FLAGS_##NAME;             \
     /*COMMENT*/
#define DEFINE_bool(NAME, DEFAULT, COMMENT) DEFINE__(bool, NAME, DEFAULT, COMMENT)
#define DEFINE_int32(NAME, DEFAULT, COMMENT) DEFINE__(int, NAME, DEFAULT, COMMENT)
#define DEFINE_int64(NAME, DEFAULT, COMMENT) DEFINE__(long, NAME, DEFAULT, COMMENT)
#define DEFINE_uint64(NAME, DEFAULT, COMMENT) DEFINE__(unsigned long, NAME, DEFAULT, COMMENT)
#define DEFINE_double(NAME, DEFAULT, COMMENT) DEFINE__(double, NAME, DEFAULT, COMMENT)
#define DEFINE_string(NAME, DEFAULT, COMMENT) DEFINE__(std::string, NAME, DEFAULT, COMMENT)

#define INIT_FLAG(TYPE, NAME, DEFAULT, COMMENT)                                                                \
    FLAGS_##NAME = apollo::cyber::ComponentBase::instance()->declare_parameter<TYPE>("FLAGS_" #NAME, DEFAULT); \
    ADEBUG << "FLAGS_" #NAME << " = " << FLAGS_##NAME;

#define INIT_FLAG_bool(NAME, DEFAULT, COMMENT) INIT_FLAG(bool, NAME, DEFAULT, COMMENT)
#define INIT_FLAG_int32(NAME, DEFAULT, COMMENT) INIT_FLAG(int, NAME, DEFAULT, COMMENT)
#define INIT_FLAG_int64(NAME, DEFAULT, COMMENT) INIT_FLAG(long, NAME, DEFAULT, COMMENT)
#define INIT_FLAG_uint64(NAME, DEFAULT, COMMENT) INIT_FLAG(unsigned long, NAME, DEFAULT, COMMENT)
#define INIT_FLAG_double(NAME, DEFAULT, COMMENT) INIT_FLAG(double, NAME, DEFAULT, COMMENT)
#define INIT_FLAG_string(NAME, DEFAULT, COMMENT) INIT_FLAG(std::string, NAME, DEFAULT, COMMENT);\
        apollo::cyber::ComponentBase::instance()->replaceRoot(FLAGS_##NAME)
        