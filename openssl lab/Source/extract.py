from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import serialization
import sys

def read_private_key_from_pem(file_path):
    with open(file_path, 'rb') as key_file:
        # Load the private key from the PEM file
        private_key = serialization.load_pem_private_key(
            key_file.read(),
            password=None,  # No password protection
            backend=default_backend()
        )

        # Access private key components
        private_numbers = private_key.private_numbers()
        n = private_numbers.public_numbers.n
        e = private_numbers.public_numbers.e
        d = private_numbers.d
        p = private_numbers.p
        q = private_numbers.q
        dp = private_numbers.dmp1
        dq = private_numbers.dmq1
        iqmp = private_numbers.iqmp

        # Print key information
        print(f"Modulus (n): {n}")
        print(f"Public Exponent (e): {e}")
        print(f"Private Exponent (d): {d}")
        print(f"Prime1 (p): {p}")
        print(f"Prime2 (q): {q}")
        print(f"Exponent1 (d mod (p-1)): {dp}")
        print(f"Exponent2 (d mod (q-1)): {dq}")
        print(f"Coefficient ((inverse of q) mod p): {iqmp}")

def read_public_key_from_pem(file_path):
    with open(file_path, 'rb') as key_file:
        # Load the public key from the PEM file
        public_key = serialization.load_pem_public_key(
            key_file.read(),
            backend=default_backend()
        )

        # Access public key components
        public_numbers = public_key.public_numbers()
        n = public_numbers.n
        e = public_numbers.e

        # Print key information
        print(f"Modulus (n): {n}")
        print(f"Public Exponent (e): {e}")

# Provide the path to your private key file
# private_key_file_path = 'pub.pem'

# Call the function to read and print private key information
# read_private_key_from_pem(private_key_file_path)

if __name__ == '__main__':
  if len(sys.argv) < 3:
    print('''Invalid arguments. 
Usage: python extract.py --pub <filename>.pem
 --pub: public key
 --priv: private key''')
    sys.exit(0)
  try:
    if(sys.argv[1]=="--pub"):
       read_public_key_from_pem(sys.argv[2])
    else:
       read_private_key_from_pem(sys.argv[2])
  except KeyboardInterrupt:
    sys.exit(0)
  except KeyError as e:
    sys.stderr.write("Error: %s\n" % (e.message))
    sys.exit(1)