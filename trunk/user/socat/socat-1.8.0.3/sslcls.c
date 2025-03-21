/* source: sslcls.c */
/* Copyright Gerhard Rieger and contributors (see file CHANGES) */
/* Published under the GNU General Public License V.2, see file COPYING */

/* explicit system call and C library trace function, for those who miss strace
 */

#include "config.h"
#include "xioconfig.h"	/* what features are enabled */

#if WITH_SYCLS && WITH_OPENSSL

#include "sysincludes.h"

#include "mytypes.h"
#include "compat.h"
#include "errno.h"

#include "error.h"
#include "filan.h"
#include "sysutils.h"
#include "sycls.h"

#if HAVE_OPENSSL_INIT_SSL
/* OpenBSD 7.2 does not know OPENSSL_INIT_SETTING */
int sycOPENSSL_init_ssl(uint64_t opts, const void *settings) {
   int result;
   Debug2("OPENSSL_init_ssl("F_uint64_t", %p)", opts, settings);
   result = OPENSSL_init_ssl(opts, settings);
   Debug1("OPENSSL_init_ssl() -> %d", result);
   return result;
}
#endif

#if !(defined(HAVE_OPENSSL_INIT_SSL) && defined(HAVE_OPENSSL_INIT_new))
void sycSSL_load_error_strings(void) {
   Debug("SSL_load_error_strings()");
   SSL_load_error_strings();
   Debug("SSL_load_error_strings() ->");
}
#endif

#if HAVE_SSL_library_init
int sycSSL_library_init(void) {
   int result;
   Debug("SSL_library_init()");
   result = SSL_library_init();
   Debug1("SSL_library_init() -> %d", result);
   return result;
}
#endif

#if HAVE_TLS_client_method
const SSL_METHOD *sycTLS_client_method(void) {
   const SSL_METHOD *result;
   Debug("TLS_client_method()");
   result = TLS_client_method();
   Debug1("TLS_client_method() -> %p", result);
   return result;
}
#endif

#if HAVE_TLS_server_method
const SSL_METHOD *sycTLS_server_method(void) {
   const SSL_METHOD *result;
   Debug("TLS_server_method()");
   result = TLS_server_method();
   Debug1("TLS_server_method() -> %p", result);
   return result;
}
#endif

#if HAVE_SSLv2_client_method
const SSL_METHOD *sycSSLv2_client_method(void) {
   const SSL_METHOD *result;
   Debug("SSLv2_client_method()");
   result = SSLv2_client_method();
   Debug1("SSLv2_client_method() -> %p", result);
   return result;
}
#endif

#if HAVE_SSLv2_server_method
const SSL_METHOD *sycSSLv2_server_method(void) {
   const SSL_METHOD *result;
   Debug("SSLv2_server_method()");
   result = SSLv2_server_method();
   Debug1("SSLv2_server_method() -> %p", result);
   return result;
}
#endif

#if HAVE_SSLv3_client_method
const SSL_METHOD *sycSSLv3_client_method(void) {
   const SSL_METHOD *result;
   Debug("SSLv3_client_method()");
   result = SSLv3_client_method();
   Debug1("SSLv3_client_method() -> %p", result);
   return result;
}
#endif

#if HAVE_SSLv3_server_method
const SSL_METHOD *sycSSLv3_server_method(void) {
   const SSL_METHOD *result;
   Debug("SSLv3_server_method()");
   result = SSLv3_server_method();
   Debug1("SSLv3_server_method() -> %p", result);
   return result;
}
#endif

const SSL_METHOD *sycSSLv23_client_method(void) {
   const SSL_METHOD *result;
   Debug("SSLv23_client_method()");
   result = SSLv23_client_method();
   Debug1("SSLv23_client_method() -> %p", result);
   return result;
}

const SSL_METHOD *sycSSLv23_server_method(void) {
   const SSL_METHOD *result;
   Debug("SSLv23_server_method()");
   result = SSLv23_server_method();
   Debug1("SSLv23_server_method() -> %p", result);
   return result;
}

#if HAVE_TLSv1_client_method
const SSL_METHOD *sycTLSv1_client_method(void) {
   const SSL_METHOD *result;
   Debug("TLSv1_client_method()");
   result = TLSv1_client_method();
   Debug1("TLSv1_client_method() -> %p", result);
   return result;
}
#endif

#if HAVE_TLSv1_server_method
const SSL_METHOD *sycTLSv1_server_method(void) {
   const SSL_METHOD *result;
   Debug("TLSv1_server_method()");
   result = TLSv1_server_method();
   Debug1("TLSv1_server_method() -> %p", result);
   return result;
}
#endif

#if HAVE_TLSv1_1_client_method
const SSL_METHOD *sycTLSv1_1_client_method(void) {
   const SSL_METHOD *result;
   Debug("TLSv1_1_client_method()");
   result = TLSv1_1_client_method();
   Debug1("TLSv1_1_client_method() -> %p", result);
   return result;
}
#endif

#if HAVE_TLSv1_1_server_method
const SSL_METHOD *sycTLSv1_1_server_method(void) {
   const SSL_METHOD *result;
   Debug("TLSv1_1_server_method()");
   result = TLSv1_1_server_method();
   Debug1("TLSv1_1_server_method() -> %p", result);
   return result;
}
#endif

#if HAVE_TLSv1_2_client_method
const SSL_METHOD *sycTLSv1_2_client_method(void) {
   const SSL_METHOD *result;
   Debug("TLSv1_2_client_method()");
   result = TLSv1_2_client_method();
   Debug1("TLSv1_2_client_method() -> %p", result);
   return result;
}
#endif

#if HAVE_TLSv1_2_server_method
const SSL_METHOD *sycTLSv1_2_server_method(void) {
   const SSL_METHOD *result;
   Debug("TLSv1_2_server_method()");
   result = TLSv1_2_server_method();
   Debug1("TLSv1_2_server_method() -> %p", result);
   return result;
}
#endif

#if HAVE_DTLS_client_method
const SSL_METHOD *sycDTLS_client_method(void) {
   const SSL_METHOD *result;
   Debug("DTLS_client_method()");
   result = DTLS_client_method();
   Debug1("DTLS_client_method() -> %p", result);
   return result;
}
#endif

#if HAVE_DTLS_server_method
const SSL_METHOD *sycDTLS_server_method(void) {
   const SSL_METHOD *result;
   Debug("DTLS_server_method()");
   result = DTLS_server_method();
   Debug1("DTLS_server_method() -> %p", result);
   return result;
}
#endif

#if HAVE_DTLSv1_client_method
const SSL_METHOD *sycDTLSv1_client_method(void) {
   const SSL_METHOD *result;
   Debug("DTLSv1_client_method()");
   result = DTLSv1_client_method();
   Debug1("DTLSv1_client_method() -> %p", result);
   return result;
}
#endif

#if HAVE_DTLSv1_server_method
const SSL_METHOD *sycDTLSv1_server_method(void) {
   const SSL_METHOD *result;
   Debug("DTLSv1_server_method()");
   result = DTLSv1_server_method();
   Debug1("DTLSv1_server_method() -> %p", result);
   return result;
}
#endif

#if HAVE_DTLSv1_2_client_method
const SSL_METHOD *sycDTLSv1_2_client_method(void) {
   const SSL_METHOD *result;
   Debug("DTLSv1_2_client_method()");
   result = DTLSv1_2_client_method();
   Debug1("DTLSv1_2_client_method() -> %p", result);
   return result;
}
#endif

#if HAVE_DTLSv1_2_server_method
const SSL_METHOD *sycDTLSv1_2_server_method(void) {
   const SSL_METHOD *result;
   Debug("DTLSv1_2_server_method()");
   result = DTLSv1_2_server_method();
   Debug1("DTLSv1_2_server_method() -> %p", result);
   return result;
}
#endif

SSL_CTX *sycSSL_CTX_new(const SSL_METHOD *method) {
   SSL_CTX *result;
   Debug1("SSL_CTX_new(%p)", method);
   result = SSL_CTX_new(method);
   Debug1("SSL_CTX_new() -> %p", result);
   return result;
}

SSL *sycSSL_new(SSL_CTX *ctx) {
   SSL *result;
   Debug1("SSL_new(%p)", ctx);
   result = SSL_new(ctx);
   Debug1("SSL_new() -> %p", result);
   return result;
}

int sycSSL_CTX_load_verify_locations(SSL_CTX *ctx, const char *CAfile,
				     const char *CApath) {
   int result;
   Debug7("SSL_CTX_load_verify_locations(%p, %s%s%s, %s%s%s)", ctx,
	  CAfile?"\"":"", CAfile?CAfile:"", CAfile?"\"":"",
	  CApath?"\"":"", CApath?CApath:"", CApath?"\"":"");
   result = SSL_CTX_load_verify_locations(ctx, CAfile, CApath);
   Debug1("SSL_CTX_load_verify_locations() -> %d", result);
   return result;
}

int sycSSL_CTX_use_certificate_file(SSL_CTX *ctx, const char *file, int type) {
   int result;
   Debug3("SSL_CTX_use_certificate_file(%p, \"%s\", %d)", ctx, file, type);
   result = SSL_CTX_use_certificate_file(ctx, file, type);
   Debug1("SSL_CTX_use_certificate_file() -> %d", result);
   return result;
}

int sycSSL_CTX_use_certificate_chain_file(SSL_CTX *ctx, const char *file) {
   int result;
   Debug2("SSL_CTX_use_certificate_chain_file(%p, \"%s\")", ctx, file);
   result = SSL_CTX_use_certificate_chain_file(ctx, file);
   Debug1("SSL_CTX_use_certificate_chain_file() -> %d", result);
   return result;
}

int sycSSL_CTX_use_PrivateKey_file(SSL_CTX *ctx, const char *file, int type) {
   int result;
   Debug3("SSL_CTX_use_PrivateKey_file(%p, \"%s\", %d)", ctx, file, type);
   result = SSL_CTX_use_PrivateKey_file(ctx, file, type);
   Debug1("SSL_CTX_use_PrivateKey_file() -> %d", result);
   return result;
}

void sycSSL_CTX_set_verify(SSL_CTX *ctx, int mode,
			   int (*verify_callback)(int, X509_STORE_CTX *)) {
   Debug3("SSL_CTX_set_verify(%p, %u, %p)", ctx, mode, verify_callback);
   SSL_CTX_set_verify(ctx, mode, verify_callback);
   Debug("SSL_CTX_set_verify() -> ");
}

int sycSSL_CTX_set_cipher_list(SSL_CTX *ctx, const char *str) {
   int result;
   Debug2("SSL_CTX_set_cipher_list(%p, \"%s\")", ctx, str);
   result = SSL_CTX_set_cipher_list(ctx, str);
   Debug1("SSL_CTX_set_cipher_list() -> %d", result);
   return result;
}

int sycSSL_CTX_set_tmp_dh(SSL_CTX *ctx, DH *dh) {
   int result;
   Debug2("SSL_CTX_set_tmp_dh(%p, %p)", ctx, dh);
   result = SSL_CTX_set_tmp_dh(ctx, dh);
   Debug1("SSL_CTX_set_tmp_dh() -> %d", result);
   return result;
}

#if HAVE_SSL_CTX_set_tlsext_max_fragment_length || defined(SSL_CTX_set_tlsext_max_fragment_length)
int sycSSL_CTX_set_tlsext_max_fragment_length(SSL_CTX *ctx, uint8_t mode) {
   int result;
   Debug2("SSL_CTX_set_tlsext_max_fragment_length(%p, %u)", ctx, mode);
   result = SSL_CTX_set_tlsext_max_fragment_length(ctx, mode);
   Debug1("SSL_CTX_set_tlsext_max_fragment_length() -> %d", result);
   return result;
}
#endif

#if HAVE_SSL_CTX_set_max_send_fragment || defined(SSL_CTX_set_max_send_fragment)
int sycSSL_CTX_set_max_send_fragment(SSL_CTX *ctx, long msf) {
   int result;
   Debug2("SSL_CTX_set_max_send_fragment(%p, %ld)", ctx, msf);
   result = SSL_CTX_set_max_send_fragment(ctx, msf);
   Debug1("SSL_CTX_set_max_send_fragment() -> %d", result);
   return result;
}
#endif

int sycSSL_set_cipher_list(SSL *ssl, const char *str) {
   int result;
   Debug2("SSL_set_cipher_list(%p, \"%s\")", ssl, str);
   result = SSL_set_cipher_list(ssl, str);
   Debug1("SSL_set_cipher_list() -> %d", result);
   return result;
}

long sycSSL_get_verify_result(SSL *ssl) {
   long result;
   Debug1("SSL_get_verify_result(%p)", ssl);
   result = SSL_get_verify_result(ssl);
   Debug1("SSL_get_verify_result() -> %lx", result);
   return result;
}

int sycSSL_set_fd(SSL *ssl, int fd) {
   int result;
   Debug2("SSL_set_fd(%p, %d)", ssl, fd);
   result = SSL_set_fd(ssl, fd);
   Debug1("SSL_set_fd() -> %d", result);
   return result;
}

int sycSSL_connect(SSL *ssl) {
   int result;
   Debug1("SSL_connect(%p)", ssl);
   result = SSL_connect(ssl);
   if (!diag_in_handler) diag_flush();
   Debug1("SSL_connect() -> %d", result);
   return result;
}

int sycSSL_accept(SSL *ssl) {
   int result;
   Debug1("SSL_accept(%p)", ssl);
   result = SSL_accept(ssl);
   Debug1("SSL_accept() -> %d", result);
   return result;
}

int sycSSL_read(SSL *ssl, void *buf, int num) {
   int result;
   Debug3("SSL_read(%p, %p, %d)", ssl, buf, num);
   result = SSL_read(ssl, buf, num);
   Debug1("SSL_read() -> %d", result);
   return result;
}

int sycSSL_pending(SSL *ssl) {
   int result;
   Debug1("SSL_pending(%p)", ssl);
   result = SSL_pending(ssl);
   Debug1("SSL_pending() -> %d", result);
   return result;
}

int sycSSL_write(SSL *ssl, const void *buf, int num) {
   int result;
   Debug3("SSL_write(%p, %p, %d)", ssl, buf, num);
   result = SSL_write(ssl, buf, num);
   Debug1("SSL_write() -> %d", result);
   return result;
}

X509 *sycSSL_get_peer_certificate(SSL *ssl) {
   X509 *result;
   Debug1("SSL_get_peer_certificate(%p)", ssl);
   result = SSL_get_peer_certificate(ssl);
   if (result) {
      Debug1("SSL_get_peer_certificate() -> %p", result);
   } else {
      Debug("SSL_get_peer_certificate() -> NULL");
   }
   return result;
}

int sycSSL_shutdown(SSL *ssl) {
   int result;
   Debug1("SSL_shutdown(%p)", ssl);
   result = SSL_shutdown(ssl);
   Debug1("SSL_shutdown() -> %d", result);
   return result;
}

void sycSSL_CTX_free(SSL_CTX *ctx) {
   Debug1("SSL_CTX_free(%p)", ctx);
   SSL_CTX_free(ctx);
   Debug("SSL_CTX_free() -> void");
   return;
}

void sycSSL_free(SSL *ssl) {
   Debug1("SSL_free(%p)", ssl);
   SSL_free(ssl);
   Debug("SSL_free() -> void");
   return;
}

#if !defined(OPENSSL_NO_EGD) && HAVE_RAND_egd
int sycRAND_egd(const char *path) {
   int result;
   Debug1("RAND_egd(\"%s\")", path);
   result = RAND_egd(path);
   Debug1("RAND_egd() -> %d", result);
   return result;
}
#endif

DH *sycPEM_read_bio_DHparams(BIO *bp, DH **x, pem_password_cb *cb, void *u) {
   DH *result;
   Debug4("PEM_read_bio_DHparams(%p, %p, %p, %p)",
	  bp, x, cb, u);
   result = PEM_read_bio_DHparams(bp, x, cb, u);
   if (result) {
      /*Debug2("PEM_read_bio_DHparams(, {%p},,) -> %p", *x, result);*/
      Debug1("PEM_read_bio_DHparams() -> %p", result);
   } else {
      Debug("PEM_read_bio_DHparams() -> NULL");
   }
   return result;
}

BIO *sycBIO_new_file(const char *filename, const char *mode) {
   BIO *result;
   Debug2("BIO_new_file(\"%s\", \"%s\")", filename, mode);
   result = BIO_new_file(filename, mode);
   if (result) {
      Debug1("BIO_new_file() -> %p", result);
   } else {
      Debug("BIO_new_file() -> NULL");
   }
   return result;
}

#if WITH_FIPS
int sycFIPS_mode_set(int onoff) {
   int result;
   Debug1("FIPS_mode_set(%d)", onoff);
   result = FIPS_mode_set(onoff);
   Debug1("FIPS_mode_set() -> %d", result);
   return result;
}
#endif /* WITH_FIPS */

#if OPENSSL_VERSION_NUMBER >= 0x00908000L && !defined(OPENSSL_NO_COMP)
const COMP_METHOD *sycSSL_get_current_compression(SSL *ssl) {
   const COMP_METHOD *result;
   Debug1("SSL_get_current_compression(%p)", ssl);
   result = SSL_get_current_compression(ssl);
   if (result) {
      Debug1("SSL_get_current_compression() -> %p", result);
   } else {
      Debug("SSL_get_current_compression() -> NULL");
   }
   return result;
}

const COMP_METHOD *sycSSL_get_current_expansion(SSL *ssl) {
   const COMP_METHOD *result;
   Debug1("SSL_get_current_expansion(%p)", ssl);
   result = SSL_get_current_expansion(ssl);
   if (result) {
      Debug1("SSL_get_current_expansion() -> %p", result);
   } else {
      Debug("SSL_get_current_expansion() -> NULL");
   }
   return result;
}

const char *sycSSL_COMP_get_name(const COMP_METHOD *comp) {
   const char *result;
   Debug1("SSL_COMP_get_name(%p)", comp);
   result = SSL_COMP_get_name(comp);
   if (result) {
      Debug1("SSL_COMP_get_name() -> \"%s\"", result);
   } else {
      Debug("SSL_COMP_get_name() -> NULL");
   }
   return result;
}
#endif

#endif /* WITH_SYCLS && WITH_OPENSSL */
