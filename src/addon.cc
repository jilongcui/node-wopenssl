#include <cstdlib>
#include <cstdio>

#include <addon.h>
#include <x509.h>
#include <pkcs12.h>

using namespace v8;

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("version"), String::New(VERSION));
  exports->Set(String::NewSymbol("getAltNames"), FunctionTemplate::New(get_altnames)->GetFunction());
  exports->Set(String::NewSymbol("getSubject"), FunctionTemplate::New(get_subject)->GetFunction());
  exports->Set(String::NewSymbol("getIssuer"), FunctionTemplate::New(get_issuer)->GetFunction());
  exports->Set(String::NewSymbol("parseCert"), FunctionTemplate::New(parse_cert)->GetFunction());
  exports->Set(String::NewSymbol("extractP12"), FunctionTemplate::New(extract_p12)->GetFunction());
  exports->Set(String::NewSymbol("verifycrl"), FunctionTemplate::New(verifycrl)->GetFunction());
}

NODE_MODULE(wopenssl, init)
