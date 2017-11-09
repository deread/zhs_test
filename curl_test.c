#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<curl/curl.h>
#include <stdlib.h>


int main()
{

    CURL *curl = NULL;

    //1.穿件一个句柄
    curl = curl_easy_init();
    if(curl) {
        CURLcode res;
      res =   curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
      if(res != CURLE_OK)
      {
          printf("curl curl_easy_seopt err ");
          exit(1);
      }
        res = curl_easy_setopt(curl,CURLOPT_POST,0);
      if(res != CURLE_OK)
      {
          printf("curl curl_easy_seopt err ");
          exit(1);
      }

        res = curl_easy_perform(curl);
      if(res != CURLE_OK)
      {
          printf("curl curl_easy_perform err ");
          exit(1);
      }

        curl_easy_cleanup(curl);
    }

    return 0;
}
