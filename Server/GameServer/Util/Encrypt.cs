using System.Security.Cryptography;
using System.Text;
namespace Zee
{
    public class Encryption
    {
        static public RSACryptoServiceProvider rsa = new();

        static byte[] EncryptData(string data, string publicKey)
        {
            rsa.FromXmlString(publicKey);
            byte[] plainBytes = Encoding.UTF8.GetBytes(data);
            return rsa.Encrypt(plainBytes, false);
        }

        static string DecryptData(byte[] encryptedData, string privateKey)
        {
            rsa.FromXmlString(privateKey);
            return Encoding.UTF8.GetString(rsa.Decrypt(encryptedData, false));
        }

        static public void Test()
        {
            // 비대칭키 생성
            // 공개키와 개인키 생성
            var publicKey = rsa.ToXmlString(false);
            var privateKey = rsa.ToXmlString(true);

            Console.WriteLine("공개키:\n" + publicKey);
            Console.WriteLine("개인키:\n" + privateKey);

            // 메시지 암호화
            string originalMessage = "Hello, World!";
            byte[] encryptedData = EncryptData(originalMessage, publicKey);

            // 메시지 복호화
            string decryptedMessage = DecryptData(encryptedData, privateKey);
            Console.WriteLine("복호화된 메시지: " + decryptedMessage);
        }
    }
}
