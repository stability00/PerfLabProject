/* -------------------------------------------------------------------------------
	Script Title       : 
	Script Description : 
                        
                        
	Recorder Version   : 0
   ------------------------------------------------------------------------------- */

vuser_init()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_url("manifest.json", 
		"URL=https://dev-boomq.pflb.ru/manifest.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-Client-Date", 
		"2026-02-02T10:41:12.057Z");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"142\", \"YaBrowser\";v=\"25.12\", \"Not_A Brand\";v=\"99\", \"Yowser\";v=\"2.5\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=admin_gr3@mail.com", ENDITEM, 
		"Name=password", "Value=Wsx321!@#", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		LAST);

	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

	web_url("22", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team/22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("boomq_auth="
		"eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc19ub3RpZmljYXRlZCI6ZmFsc2UsInVzZXJfaWQiOjE5MjUsInVzZXJfbmFtZSI6ImFkbWluX2dyM0BtYWlsLmNvbSIsInNjb3BlIjpbInRydXN0IiwicmVhZCIsIndyaXRlIl0sInRlYW1fbWVtYmVyIjoie1wiaWRcIjoyMDA5LFwidGVhbUlkXCI6MjIsXCJ1c2VySWRcIjoxOTI1LFwiZW1haWxcIjpcImFkbWluX2dyM0BtYWlsLmNvbVwiLFwidXNlckRpc3BsYXlOYW1lXCI6XCJhZG1pbl9ncjNcIixcInBlcm1pc3Npb25MaXN0XCI6W1wiVklFV1wiLFwiQURNSU5cIixcIkVESVRcIixcIk1BTkFHRV9VU0VSU19JTl9PUkdcIixcIlJVTlwiXSxcImludml0YXRpb25TdGF0dXNcIjpcIkFDQ0VQVEVEXCIsXCJpb"
		"nZpdGVVcmxcIjpudWxsLFwiZXhwaXJlZEF0XCI6bnVsbCxcImNyZWF0ZUF0XCI6XCIyMDI2LTAxLTI4VDA3OjMxOjEwLjgyOFpcIixcInVwZGF0ZWRBdFwiOlwiMjAyNi0wMS0yOFQwNzozMjoyNy43MTJaXCJ9IiwidXNlcl9sYW5ndWFnZSI6IlJVIiwidGVhbV9pZCI6MjIsImV4cCI6MTc3MDA3MTQxMCwiYXV0aG9yaXRpZXMiOlsiUk9MRV9VU0VSIl0sImp0aSI6ImRjOGVmNjM3LWYwOWMtNDQ0MC05NGY5LWJjNDVmZTlhNjIwYSIsImNsaWVudF9pZCI6ImNsaWVudCJ9.lZQ-8TWW6ajQHvOp7rxJR3sHxzuBReZC_3orYB6-Xm3khH9bah0FpcwVXYTtB2sgy6eyv0rGM9ewTd0vWh2r-lhZJEpEBn7o3A1U6YRTgV51JofuXF0mg3rTBJ3ZuehG1_nEYrN5kfy27ucLnr"
		"sq5v2cb_WZX4yF-QLNoLuaC5YX_AOlSJ84hxblYNbGBDicVwlqMrvhz6bexCmftacbWkrNhKZpbU1MHKBGtTOpojs8mcfjBoax3TIz7bx_obGIa_6aCjCL4PBpJ5mIvBrdsUPdI8KBPZ-G_z2dYRZFYMepx6FfJyAdTa8v7bX8-iV8SYVbFC9uZNN4zJiqjN7dGA; DOMAIN=dev-boomq.pflb.ru");

	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}