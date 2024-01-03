from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import padding
import sys

def encrypt_rsa(plainPath, public_key_file,cipherPath):
    with open(plainPath, 'r') as file:
        message = file.read()
    # Load public key
    with open(public_key_file, 'rb') as key_file:
        public_key = serialization.load_pem_public_key(
            key_file.read(),
            backend=default_backend()
        )

    # Encrypt the message using RSAES-PKCS1-V1_5 padding
    ciphertext = public_key.encrypt(
        message.encode('utf-8'),
        padding.PKCS1v15()
    )
    with open(cipherPath, 'wb') as file:
        file.write(ciphertext)
    return ciphertext

if __name__ == "__main__":
    # Example usage:
    plainPath="plain.txt"
    public_key_file = "pub.pem"
    cipherPath="cipher.txt"
    plainPath=sys.argv[1]
    publicPath=sys.argv[2]
    output_file=sys.argv[3]

    encrypted_data = encrypt_rsa(plainPath, public_key_file,cipherPath)