Action()
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
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("UC05_TR01_Login");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-Client-Date", 
		"2026-02-03T08:17:55.192Z");

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
		"Snapshot=t2.inf", 
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
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("22", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team/22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("boomq_auth="
		"eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc19ub3RpZmljYXRlZCI6ZmFsc2UsInVzZXJfaWQiOjE5MjUsInVzZXJfbmFtZSI6ImFkbWluX2dyM0BtYWlsLmNvbSIsInNjb3BlIjpbInRydXN0IiwicmVhZCIsIndyaXRlIl0sInRlYW1fbWVtYmVyIjoie1wiaWRcIjoyMDA5LFwidGVhbUlkXCI6MjIsXCJ1c2VySWRcIjoxOTI1LFwiZW1haWxcIjpcImFkbWluX2dyM0BtYWlsLmNvbVwiLFwidXNlckRpc3BsYXlOYW1lXCI6XCJhZG1pbl9ncjNcIixcInBlcm1pc3Npb25MaXN0XCI6W1wiVklFV1wiLFwiQURNSU5cIixcIkVESVRcIixcIk1BTkFHRV9VU0VSU19JTl9PUkdcIixcIlJVTlwiXSxcImludml0YXRpb25TdGF0dXNcIjpcIkFDQ0VQVEVEXCIsXCJpb"
		"nZpdGVVcmxcIjpudWxsLFwiZXhwaXJlZEF0XCI6bnVsbCxcImNyZWF0ZUF0XCI6XCIyMDI2LTAxLTI4VDA3OjMxOjEwLjgyOFpcIixcInVwZGF0ZWRBdFwiOlwiMjAyNi0wMS0yOFQwNzozMjoyNy43MTJaXCJ9IiwidXNlcl9sYW5ndWFnZSI6IlJVIiwidGVhbV9pZCI6MjIsImV4cCI6MTc3MDE0OTc0OCwiYXV0aG9yaXRpZXMiOlsiUk9MRV9VU0VSIl0sImp0aSI6IjY5YTJjNGE2LWUxNWQtNDIyNy05NDEzLTRiMWExOTFmM2FlZSIsImNsaWVudF9pZCI6ImNsaWVudCJ9.Ge9BwAfWxo2hvfvbrI-Q-r8qnyh3hPWgXHvAnBN5KoI7Js7AtiO34iTbG1mFOfJTK2VwZufSaC00SNlR7PezdTMspg44Ot7YQXX0hVeksKcCF-bG486MpUY5PHh79GsDUmwbXBOMefwbSCesDt"
		"X-c1ctjQH6t1yYRXNUD4EQe1PZsGhxIUyAZnSVBjDdRGMXwpa4Wkq5rntxHfjIQK9S7FaHIgy2hhEl91iz0iJs0_gzwmrBwwbljrKl6_hfDN7FGAzDiXNLQED5K4J3CT0SEdNVFOc3Ajd_THilaSr9V9h2sS2ChoMNi753Mh9LfJz8w4Lv-IvrN-yYVtTIqQnDhg; DOMAIN=dev-boomq.pflb.ru");

	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC05_TR01_Login",LR_AUTO);

	lr_think_time(31);

	lr_start_transaction("UC05_TR02_ПросмотрЗапусков");

	web_url("project", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&size=999", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_url("label", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test/label?query=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_url("user_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_url("test", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&displayState=INITIALIZATION,WAITING,RUNNING,TEST_STOPPING", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_url("test_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&page=0&size=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC05_TR02_ПросмотрЗапусков",LR_AUTO);

	web_url("test_3", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&displayState=INITIALIZATION,WAITING,RUNNING,TEST_STOPPING", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(6);

	lr_start_transaction("UC05_TR03_ПросмотрТеста");

	web_url("2698", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/2698", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_url("8399", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test/8399", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testMetric", 
		"URL=https://dev-boomq.pflb.ru/timescale-srv/testMetric?testId=8399&testStartDate=2026-02-03T07:57:03.599Z&testEndDate=2026-02-03T07:58:01.889Z", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_url("auth", 
		"URL=https://dev-boomq.pflb.ru/grafana-srv/auth?testId=8399&testStartTime=2026-02-03T07:57:03.599Z&testEndTime=2026-02-03T07:58:01.889Z", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testResultFile", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId=8399", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("testResultFile_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId=8399", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC05_TR03_ПросмотрТеста",LR_AUTO);

	web_url("testResultFile_3", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId=8399", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("testResultFile_4", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId=8399", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("testResultFile_5", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId=8399", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("testResultFile_6", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId=8399", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(4);

	lr_start_transaction("UC05_TR04_ДобавлениеSLA");

	web_url("downloadLink", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/2698/version/3930/downloadLink", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/minio/boomq/boomq/teams/22/projects/2698/v_3930.yaml?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIOSFODNN7EXAMPLE/20260203/us-east-1/s3/aws4_request&X-Amz-Date=20260203T082018Z&X-Amz-Expires=604800&X-Amz-SignedHeaders=host&X-Amz-Signature=448bc9cfb394185d6aca19049e0fa5c3d63eb0f1fe92e5879c0e02b46a23eb14", "Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", ENDITEM, 
		LAST);

	web_url("testResultFile_7", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId=8399", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testResultFile_8", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId=8399", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("testResultFile_9", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId=8399", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("testResultFile_10", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId=8399", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	web_url("8399_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test/8399", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(10);

	web_custom_request("sla", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResult/sla?testId=8399", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/2698/8399", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[{\"type\":\"GENERAL_TEST_SLA\",\"targetType\":\"TEST\",\"slaList\":[{\"fromDate\":7,\"restrictionType\":\"ERROR_RATE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":31,\"value\":\"2\"}]}]", 
		LAST);

	lr_end_transaction("UC05_TR04_ДобавлениеSLA",LR_AUTO);

	lr_think_time(83);

	lr_start_transaction("UC05_TR05_Добавление треда1_переход");

	web_url("slaReportProfile", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

	web_url("project_2", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&size=999", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC05_TR05_Добавление треда1_переход",LR_AUTO);

	lr_think_time(14);

	lr_start_transaction("UC05_TR06_ДобавлениеТренда2_Заполнение1");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"142\", \"YaBrowser\";v=\"25.12\", \"Not_A Brand\";v=\"99\", \"Yowser\";v=\"2.5\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	lr_think_time(8);

	web_url("test_9", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&size=999999&projectId=2698&state=FINISHED,FAILED,CANCELED", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t65.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(12);

	web_custom_request("slaTypeList", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/slaTypeList", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t66.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":2698,\"testFilterExpressionList\":[{\"type\":\"TEST_DISPLAY_STATE_EXPRESSION\",\"testDisplayStateList\":[\"FINISHED\",\"FAILED\",\"CANCELED\"]}]}", 
		LAST);

	web_custom_request("previewReport", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t67.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":2698,\"testFilterExpressionList\":[{\"type\":\"TEST_DISPLAY_STATE_EXPRESSION\",\"testDisplayStateList\":[\"FINISHED\",\"FAILED\",\"CANCELED\"]}],\"chartProfileList\":[],\"tableProfileList\":[]}", 
		LAST);

	lr_end_transaction("UC05_TR06_ДобавлениеТренда2_Заполнение1",LR_AUTO);

	lr_think_time(14);

	lr_start_transaction("UC05_TR06_ДобавлениеТренда3_Заполнение2");

	web_custom_request("previewReport_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":2698,\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":7,\"restrictionType\":\"ERROR_RATE\",\"targetType\":\"TEST\",\"toDate\":31,\"type\":\"GENERAL_SLA_TYPE\"}]}],\"testFilterExpressionList\":[{\"type\":\"TEST_DISPLAY_STATE_EXPRESSION\",\"testDisplayStateList\":[\"FINISHED\",\"FAILED\",\"CANCELED\"]}]}", 
		LAST);

	lr_think_time(5);

	web_custom_request("previewReport_3", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t69.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":2698,\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":7,\"restrictionType\":\"ERROR_RATE\",\"targetType\":\"TEST\",\"toDate\":31,\"type\":\"GENERAL_SLA_TYPE\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_DISPLAY_STATE_EXPRESSION\",\"testDisplayStateList\":[\"FINISHED\",\"FAILED\",\"CANCELED\"]}]}", 
		LAST);

	lr_think_time(5);

	web_custom_request("slaReportProfile_3", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t70.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"name\":\"untitled_profile_11:23\",\"projectId\":2698,\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":7,\"restrictionType\":\"ERROR_RATE\",\"targetType\":\"TEST\",\"toDate\":31,\"type\":\"GENERAL_SLA_TYPE\"}],\"orderInReport\":0}],\"tableProfileList\":[{\"tableId\":null,\"slaTypeList\":[{\"fromDate\":7,\"restrictionType\":\"ERROR_RATE\",\"targetType\":\"TEST\",\"toDate\":31,\"type\":\"GENERAL_SLA_TYPE\"}],\"valueType\":\"VALUE\",\"orderInReport\":1}],\"testFilterExpressionList\":[{\""
		"type\":\"TEST_DISPLAY_STATE_EXPRESSION\",\"testDisplayStateList\":[\"FINISHED\",\"FAILED\",\"CANCELED\"]}]}", 
		LAST);

	lr_end_transaction("UC05_TR06_ДобавлениеТренда3_Заполнение2",LR_AUTO);

	lr_start_transaction("UC05_TR08_ПроверкаСозданияТренда");

	web_revert_auto_header("Origin");

	lr_think_time(21);

	web_url("slaReportProfile_4", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles", 
		"Snapshot=t71.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC05_TR08_ПроверкаСозданияТренда",LR_AUTO);

	lr_start_transaction("UC05_TR09_Выход");

	lr_end_transaction("UC05_TR09_Выход",LR_AUTO);

	return 0;
}