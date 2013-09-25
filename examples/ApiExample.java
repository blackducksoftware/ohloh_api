/*
    The MIT License (MIT)

    Copyright (c) 2013 Black Duck Software, Inc.
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

    This is an example of using the Ohloh API from Java.
    Detailed information can be found at the Ohloh website:

    https://github.com/blackducksw/ohloh_api

    This examples retrieves a account and simply shows the name associated.

    Pass your Ohloh API key as the first parameter to this example.
    Ohloh API keys are free. If you do not have one, you can obtain one
    at the Ohloh website:

     http://www.ohloh.net/accounts/<your_login>/api_keys/new

    Pass the email address of the account as the second parameter to this script.
*/

import java.net.*;
import java.security.*;
import java.io.*;
import java.util.*;
import org.w3c.dom.*;
import javax.xml.parsers.*;

public class ApiExample
{
    private static final char[] hexChars ={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

    public static void usage()
    {
        System.out.println("Usage:");
        System.out.println("java ApiExample [api_key] [user_email]");
    }

    public ApiExample(String apiKey, String userEmail)
    {
        initiate(apiKey, userEmail);
    }

    public void initiate(String apiKey, String userEmail)
    {
        System.out.println("Initialising request.");

        // Calculate MD5 digest from the email address.
        String emailDigest = calculateDigest(userEmail);

        try
        {
            // Request XML file.
            URL url = new URL("http://www.ohloh.net/accounts/" + emailDigest + ".xml?api_key=" + apiKey + "&v=1");
            URLConnection con = url.openConnection();

            // Check for status OK.
            if (con.getHeaderField("Status").startsWith("200"))
            {
                System.out.println("Request succeeded.");
            }
            else
            {
                System.out.println("Request failed. Possibly wrong API key?");
                return;
            }
            System.out.println("Looking up name..");

            // Create a document from the URL's input stream, and parse.
            DocumentBuilder builder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
            Document doc = builder.parse(con.getInputStream());

            NodeList responseNodes = doc.getElementsByTagName("response");
            for (int i = 0; i < responseNodes.getLength(); i++)
            {
                Element element = (Element)responseNodes.item(i);

                // First check for the status code inside the XML file. It is
                //  most likely, though, that if the request would have failed,
                //  it is already returned earlier.
                NodeList statusList = element.getElementsByTagName("status");
                if (statusList.getLength() == 1)
                {
                    Node statusNode = statusList.item(0);

                    // Check if the text inidicates that the request was
                    //  successful.
                    if (!statusNode.getTextContent().equals("success"))
                    {
                        System.out.println("Failed. " + statusNode.getTextContent());
                        return;
                    }
                }

                Element resultElement = (Element)element.getElementsByTagName("result").item(0);
                // We assume we only have one account result here.
                Element accountElement = (Element)resultElement.getElementsByTagName("account").item(0);

                if (accountElement != null)
                {
                    // Lookup name.
                    String realName = accountElement.getElementsByTagName("name").item(0).getTextContent();
                    System.out.println("Located the real name: " + realName);
                }
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }

    public String calculateDigest(String email)
    {
        return hexStringFromBytes(calculateHash(email.getBytes()));
    }

    private byte[] calculateHash(byte[] dataToHash)
    {
        try
        {
            // Calculate MD5 digest.
            MessageDigest md = MessageDigest.getInstance("MD5");
            md.update(dataToHash, 0, dataToHash.length);
            return md.digest();
        }
        catch (NoSuchAlgorithmException e)
        {
            e.printStackTrace();
        }
        return null;
    }

    public String hexStringFromBytes(byte[] b)
    {
        // Conversion from bytes to String.
        String hex = "";

        int msb;

        int lsb = 0;
        int i;

        for (i = 0; i < b.length; i++)
        {
            msb = ((int)b[i] & 0x000000FF) / 16;

            lsb = ((int)b[i] & 0x000000FF) % 16;
            hex = hex + hexChars[msb] + hexChars[lsb];
        }
        return hex;
    }

    public static void main(String[] args)
    {
        if (args.length == 2)
        {
            // Simply pass arguments.
            new ApiExample(args[0], args[1]);
        }
        else
        {
            // Show usage information.
            usage();
        }
    }
}
