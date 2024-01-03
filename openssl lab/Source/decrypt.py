from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import padding
import sys

def decrypt_file(ciphertext_file, private_key_file, output_file):
    # Load private key
    with open(private_key_file, 'rb') as key_file:
        private_key = serialization.load_pem_private_key(
            key_file.read(),
            password=None,
            backend=default_backend()
        )

    # Read the ciphertext from the file
    with open(ciphertext_file, 'rb') as file:
        ciphertext = file.read()

    # Decrypt the ciphertext using RSAES-PKCS1-V1_5 padding
    plaintext = private_key.decrypt(
        ciphertext,
        padding.PKCS1v15()
    )

    # Write the decrypted plaintext to the output file
    with open(output_file, 'wb') as file:
        file.write(plaintext)

if __name__ == "__main__":
    # ciphertext_file = "cipher.txt"
    # private_key_file = "priv.pem"
    # output_file = "decoded.txt"
    ciphertext_file=sys.argv[1]
    private_key_file=sys.argv[2]
    output_file=sys.argv[3]
    try:
      decrypt_file(ciphertext_file,private_key_file,output_file)
    except KeyboardInterrupt:
      sys.exit(0)
    except KeyError as e:
      sys.stderr.write("Error: %s\n" % (e.message))
      sys.exit(1)