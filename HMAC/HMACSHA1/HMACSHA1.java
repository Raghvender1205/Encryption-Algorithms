import java.io.*;
import java.security.MessageDigest;

public class HMACSHA1 {
	// Convert byte[] to String.
    private static String byte2string(byte[] bArray)  {
		char[] hexChar = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
		char[] output = new char[2 * bArray.length];
        for (int i = 0; i < bArray.length; i++)  {
            output[2*i] = hexChar[bArray[i] >> 4 & 0x0F];
            output[2*i+1] = hexChar[bArray[i] & 0x0F];
        }
        String outputString = String.valueOf(output);
        return outputString;
    }
    
	public static void main(String[] args) {
		// Read the system arguments.
		String PasswordString = args[0];
		String FilenameString = args[1];
		System.out.println("Key         : "+ PasswordString);
		
		// Convert the password to UTF-8.
		byte[] password = null;
		try {
			password = PasswordString.getBytes("UTF-8");
		}
		catch (UnsupportedEncodingException e) {
			System.out.println(e);
	    }
		
		// Calculate Hashed Password.
		byte[] hashedpasswd = null;
		try {
			MessageDigest messageDigest = MessageDigest.getInstance("SHA1");
			messageDigest.update(password);
			hashedpasswd = messageDigest.digest();
			String hashedpwString = byte2string(hashedpasswd);
			System.out.print("Hashed Key  : ");
			System.out.println(hashedpwString);
		}
		catch (Exception e) {
			throw new RuntimeException(e);
		}
		
		// Calculate padded key.
		byte[] Key = new byte[64];
		for (int i = 0; i < hashedpasswd.length; i++) {
			Key[i] = hashedpasswd[i];
		}

		// Calculate 2 new keys.
		byte[] Key1 = new byte[64]; // XOR 0x36
		byte[] Key2 = new byte[64]; // XOR 0x5c
		for (int i = 0; i < 64; i++) {
			Key1[i] = (byte) (Key[i] ^ 0x36);
			Key2[i] = (byte) (Key[i] ^ 0x5c);
		}

		// Read text from file.
		byte[] text = null;
		try {
			InputStream istream = new FileInputStream(FilenameString);
			text = new byte[istream.available()];
			istream.read(text);
			//System.out.println(Arrays.toString(text));
			istream.close();
		}
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		catch(IOException e) {
			e.printStackTrace();
		}
		
		// Concat Key1 and text, and hash them.
		byte[] Key1text = new byte[Key1.length + text.length];
		System.arraycopy(Key1, 0, Key1text, 0, Key1.length);
		System.arraycopy(text, 0, Key1text, Key1.length, text.length);
		byte[] hashedKey1text = null;
		try {
			MessageDigest messageDigest = MessageDigest.getInstance("SHA1");
			messageDigest.update(Key1text);
			hashedKey1text = messageDigest.digest();
		}
		catch (Exception e) {
			throw new RuntimeException(e);
		}

		// Concat Key2 and hashedKey1text, and hash them.
		byte[] Key2text = new byte[Key2.length + hashedKey1text.length];
		System.arraycopy(Key2, 0, Key2text, 0, Key2.length);
		System.arraycopy(hashedKey1text, 0, Key2text, Key2.length, hashedKey1text.length);
		byte[] hashedKey2text = null;
		try {
			MessageDigest messageDigest = MessageDigest.getInstance("SHA1");
			messageDigest.update(Key2text);
			hashedKey2text = messageDigest.digest();
		}
		catch (Exception e) {
			throw new RuntimeException(e);
		}
		System.out.println("File name   : " + FilenameString);
		System.out.println("HMAC result : " + byte2string(hashedKey2text));
	}
}
