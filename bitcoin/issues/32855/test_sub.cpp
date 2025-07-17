#include <iostream>
#include <univalue.h>
#include "util/subprocess.h"  // Include subprocess library

namespace sp = subprocess;

int main() {
    // std::string str_command="/usr/local/bin/python3.9 /Users/user/data/code/bitcoin/test/functional/mocks/signer.py --fingerprint 00000001 --chain regtest getdescriptors --account 0";
    std::string str_command="/opt/homebrew/bin/python3 /Users/user/data/code/bitcoin/test/functional/mocks/signer.py --fingerprint 00000001 --chain regtest getdescriptors --account 0";
    std::string str_std_in="";
    try {
        std::istringstream stdout_stream;
        std::istringstream stderr_stream;
    
        if (str_command.empty()) return UniValue::VNULL;
    
        auto c = sp::Popen(str_command, sp::input{sp::PIPE}, sp::output{sp::PIPE}, sp::error{sp::PIPE}, sp::close_fds{true});
        if (!str_std_in.empty()) {
            c.send(str_std_in);
        }
        auto [out_res, err_res] = c.communicate();
        stdout_stream.str(std::string{out_res.buf.begin(), out_res.buf.end()});
        stderr_stream.str(std::string{err_res.buf.begin(), err_res.buf.end()});
    
        std::string result;
        std::string error;
        std::getline(stdout_stream, result);
        std::getline(stderr_stream, error);

        const int n_error = c.retcode();
        std::cout << "Subprocess stdout: " << result << std::endl;
        std::cout << "Subprocess exited with code: " << n_error << std::endl;

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;

        return 1;
    }

    return 0;
}
