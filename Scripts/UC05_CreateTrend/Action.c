Action()
{
	
    int i, count, random_index;
    char param_name[100], selected_id[100], param_name1[100], selected_id1[100], param_name2[100], selected_id2[100];
    char paramName[100];
	int reportFound = 0; // Флаг для отслеживания найден ли тренд

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

	// 1. Параметризация логина и пароля (если нужно)
    //lr_save_string("admin_gr3@mail.com", "username");
    //lr_save_string("Wsx321!@#", "password");
    
    // 2. Регистрируем правило корреляции ДО запроса
    web_set_max_html_param_len("5000");   
    web_reg_save_param("AuthToken",
        "LB=set-cookie: boomq_auth=",
        "RB=;",
        LAST);
	
	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={user_login}", ENDITEM, 
        "Name=password", "Value={user_pass}", ENDITEM, 
        "Name=submit", "Value=Login", ENDITEM, 
		LAST);

    // 4. Проверяем, что токен получен
    if (strlen(lr_eval_string("{AuthToken}")) > 0) {
        lr_output_message("Токен получен: %s", lr_eval_string("{AuthToken}"));
        lr_save_string(lr_eval_string("Bearer {AuthToken}"), "BearerToken");
		web_add_auto_header("Authorization", lr_eval_string("{BearerToken}"));
    } else {
        lr_error_message("Токен не получен!");
        return -1;
    }
    
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

	web_set_max_html_param_len("5000");   
    web_reg_save_param("NewAuthToken",
        "LB=set-cookie: boomq_auth=",
        "RB=\n",
        LAST);
	
	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	if (strlen(lr_eval_string("{NewAuthToken}")) > 0) {
        lr_output_message("Токен получен: %s", lr_eval_string("{NewAuthToken}"));
        lr_save_string(lr_eval_string("Bearer {NewAuthToken}"), "BearerToken");
		web_add_auto_header("Authorization", lr_eval_string("{BearerToken}"));
    } else {
        lr_error_message("Токен не получен!");
        return -1;
    }

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
	
	web_reg_save_param_json(
        "ParamName=completed_test_id",
        "QueryString=$.content[*].id",
        "SelectAll=Yes",
        SEARCH_FILTERS,
        LAST);
	
	web_reg_save_param_json(
        "ParamName=completed_test_projectId",
        "QueryString=$.content[*].testProjectId",
        "SelectAll=Yes",
        SEARCH_FILTERS,
        LAST);
	
	web_reg_save_param_json(
        "ParamName=completed_test_versionId",
        "QueryString=$.content[*].testProjectVersionId",
        "SelectAll=Yes",
        SEARCH_FILTERS,
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
	
	count = atoi(lr_eval_string("{completed_test_id_count}"));
    
    if (count == 0) {
        lr_error_message("Не найдено ни одного выполненного теста!");
        lr_end_transaction("UC05_TR02_ПросмотрЗапусков", LR_FAIL);
    }
	else {
	    lr_output_message("Всего проектов: %d", count);
    
	    // 4. Выводим все ID
	    for(i = 1; i <= count; i++) {
	        sprintf(param_name, "{completed_test_id_%d}", i);
	        lr_output_message("Тест %d: ID = %s", i, lr_eval_string(param_name));
	    }
	    
	    // 5. Генерируем случайный индекс (от 1 до count)
	    srand(time(NULL)); // инициализация генератора случайных чисел
	    random_index = (rand() % count) + 1; // от 1 до count включительно
	    
	    lr_output_message("Случайный индекс: %d", random_index);
	    
	    // 6. Получаем случайный ID
	    sprintf(param_name, "{completed_test_id_%d}", random_index);
	    strcpy(selected_id, lr_eval_string(param_name));
	    
	    sprintf(param_name1, "{completed_test_projectId_%d}", random_index);
	    strcpy(selected_id1, lr_eval_string(param_name1));
	    
	   	sprintf(param_name2, "{completed_test_versionId_%d}", random_index);
	    strcpy(selected_id2, lr_eval_string(param_name2));
	    
	    lr_output_message("Выбран случайный тест ID: %s", selected_id);
	    lr_output_message("Проект этого теста ID: %s", selected_id1);
	    lr_output_message("Версия этого теста ID: %s", selected_id2);
	    
	    // 7. Сохраняем для дальнейшего использования
	    lr_save_string(selected_id, "selected_completed_test_id");
	    lr_save_string(selected_id1, "selected_completed_project_id");
	    lr_save_string(selected_id2, "selected_completed_version_id");
	
		lr_end_transaction("UC05_TR02_ПросмотрЗапусков", LR_PASS);
	}
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
		"URL=https://dev-boomq.pflb.ru/project-srv/project/{selected_completed_project_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_url("8399", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test/{selected_completed_test_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testMetric", 
		"URL=https://dev-boomq.pflb.ru/timescale-srv/testMetric?testId={selected_completed_test_id}&testStartDate=2026-02-03T07:57:03.599Z&testEndDate=2026-02-03T07:58:01.889Z", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_url("auth", 
		"URL=https://dev-boomq.pflb.ru/grafana-srv/auth?testId={selected_completed_test_id}&testStartTime=2026-02-03T07:57:03.599Z&testEndTime=2026-02-03T07:58:01.889Z", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testResultFile", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId={selected_completed_test_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("testResultFile_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId={selected_completed_test_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC05_TR03_ПросмотрТеста",LR_AUTO);

	web_url("testResultFile_3", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId={selected_completed_test_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("testResultFile_4", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId={selected_completed_test_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("testResultFile_5", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId={selected_completed_test_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("testResultFile_6", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId={selected_completed_test_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(4);

	lr_start_transaction("UC05_TR04_ДобавлениеSLA");

	web_url("downloadLink", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/{selected_completed_project_id}/version/{selected_completed_version_id}/downloadLink", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/minio/boomq/boomq/teams/22/projects/2698/v_3930.yaml?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIOSFODNN7EXAMPLE/20260203/us-east-1/s3/aws4_request&X-Amz-Date=20260203T082018Z&X-Amz-Expires=604800&X-Amz-SignedHeaders=host&X-Amz-Signature=448bc9cfb394185d6aca19049e0fa5c3d63eb0f1fe92e5879c0e02b46a23eb14", "Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", ENDITEM, 
		LAST);

	web_url("testResultFile_7", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId={selected_completed_test_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testResultFile_8", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId={selected_completed_test_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("testResultFile_9", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId={selected_completed_test_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("testResultFile_10", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResultFile?testId={selected_completed_test_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	web_url("8399_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test/{selected_completed_test_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(10);
	
	web_add_header("Content-Type", "application/json");
	web_custom_request("sla", 
		"URL=https://dev-boomq.pflb.ru/test-srv/testResult/sla?testId={selected_completed_test_id}", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs/{selected_completed_project_id}/{selected_completed_test_id}", 
		"Snapshot=t31.inf", 
		"Mode=HTML",  
		"Body=[{\"type\":\"GENERAL_TEST_SLA\",\"targetType\":\"TEST\",\"slaList\":[{\"fromDate\":{from_date},\"restrictionType\":\"{restriction_type}\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":{to_date},\"value\":\"{value}\"}]}]", 
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
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&size=999999&projectId={selected_completed_project_id}&state=FINISHED,FAILED,CANCELED", 
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

	web_add_header("Content-Type", "application/json");
	web_custom_request("slaTypeList", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/slaTypeList", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t66.inf", 
		"Mode=HTML", 
		"Body={\"projectId\":{selected_completed_project_id},\"testFilterExpressionList\":[{\"type\":\"TEST_DISPLAY_STATE_EXPRESSION\",\"testDisplayStateList\":[\"FINISHED\",\"FAILED\",\"CANCELED\"]}]}", 
		LAST);

	web_add_header("Content-Type", "application/json");
	web_custom_request("previewReport", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t67.inf", 
		"Mode=HTML",  
		"Body={\"projectId\":{selected_completed_project_id},\"testFilterExpressionList\":[{\"type\":\"TEST_DISPLAY_STATE_EXPRESSION\",\"testDisplayStateList\":[\"FINISHED\",\"FAILED\",\"CANCELED\"]}],\"chartProfileList\":[],\"tableProfileList\":[]}", 
		LAST);

	lr_end_transaction("UC05_TR06_ДобавлениеТренда2_Заполнение1",LR_AUTO);

	lr_think_time(14);

	lr_start_transaction("UC05_TR07_ДобавлениеТренда3_Заполнение2");

	web_add_header("Content-Type", "application/json");
	web_custom_request("previewReport_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t68.inf", 
		"Mode=HTML", 
		"Body={\"projectId\":{selected_completed_project_id},\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":{from_date},\"restrictionType\":\"{restriction_type}\",\"targetType\":\"TEST\",\"toDate\":{to_date},\"type\":\"GENERAL_SLA_TYPE\"}]}],\"testFilterExpressionList\":[{\"type\":\"TEST_DISPLAY_STATE_EXPRESSION\",\"testDisplayStateList\":[\"FINISHED\",\"FAILED\",\"CANCELED\"]}]}", 
		LAST);
																				

	lr_think_time(5);

	web_add_header("Content-Type", "application/json");
	web_custom_request("previewReport_3", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t69.inf", 
		"Mode=HTML", 
		"Body={\"projectId\":{selected_completed_project_id},\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":{from_date},\"restrictionType\":\"{restriction_type}\",\"targetType\":\"TEST\",\"toDate\":{to_date},\"type\":\"GENERAL_SLA_TYPE\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_DISPLAY_STATE_EXPRESSION\",\"testDisplayStateList\":[\"FINISHED\",\"FAILED\",\"CANCELED\"]}]}", 
		LAST);																								

	lr_think_time(5);

	lr_save_string(lr_eval_string("Trend_{random_trend_name}"), "trend_name");
	
	
	web_reg_save_param_json(
	    "ParamName=saving_trend_id",
	    "QueryString=$.id",
	    SEARCH_FILTERS,
	    LAST);
	
	web_add_header("Content-Type", "application/json");
	web_custom_request("slaReportProfile_3", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t70.inf", 
		"Mode=HTML",  
		"Body={\"name\":\"{trend_name}\",\"projectId\":{selected_completed_project_id},\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":{from_date},\"restrictionType\":\"{restriction_type}\",\"targetType\":\"TEST\",\"toDate\":{to_date},\"type\":\"GENERAL_SLA_TYPE\"}],\"orderInReport\":0}],\"tableProfileList\":[{\"tableId\":null,\"slaTypeList\":[{\"fromDate\":{from_date},\"restrictionType\":\"{restriction_type}\",\"targetType\":\"TEST\",\"toDate\":{to_date},\"type\":\"GENERAL_SLA_TYPE\"}],\"valueType\":\"VALUE\",\"orderInReport\":1}],\"testFilterExpressionList\":[{\""
		"type\":\"TEST_DISPLAY_STATE_EXPRESSION\",\"testDisplayStateList\":[\"FINISHED\",\"FAILED\",\"CANCELED\"]}]}", 
		LAST);					

	lr_end_transaction("UC05_TR07_ДобавлениеТренда3_Заполнение2",LR_AUTO);

	lr_start_transaction("UC05_TR08_ПроверкаСозданияТренда");

	web_revert_auto_header("Origin");

	lr_think_time(21);

	web_reg_save_param_json(
	    "ParamName=all_id_trends_check",
	    "QueryString=$.[*].id",
	    "SelectAll=Yes",
	    SEARCH_FILTERS,
	    LAST);
	
	web_url("slaReportProfile_4", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles", 
		"Snapshot=t71.inf", 
		"Mode=HTML", 
		LAST);
	
	for (i = 1; i <= atoi(lr_eval_string("{all_id_trends_check_count}")); i++) {
    sprintf(paramName, "{all_id_trends_check_%d}", i);
	    
    lr_output_message("Элемент %d: OrderNumber = %s сравниваем с:%s", i, lr_eval_string(paramName), lr_eval_string("{saving_trend_id}"));
	    
    if (strcmp(lr_eval_string(paramName), lr_eval_string("{saving_trend_id}")) == 0) {
        reportFound = 1;
        break;
    }
	}
		
	if (reportFound == 1) {
		lr_output_message("Тренд успешно сохранен");
	    lr_end_transaction("UC05_TR08_ПроверкаСозданияТренда", LR_PASS);
	} else {
		lr_error_message("Тренд не сохранен");
	    lr_end_transaction("UC05_TR08_ПроверкаСозданияТренда", LR_FAIL);
	}

	//lr_end_transaction("UC05_TR08_ПроверкаСозданияТренда",LR_AUTO);

	lr_start_transaction("UC05_TR09_Выход");
	
	// 1. Очищаем все куки
	web_cleanup_cookies();
	
	// 2. Очищаем кэш
	web_cache_cleanup();
	
	// 3. Удаляем все сохраненные параметры
	web_cleanup_auto_headers();

	lr_end_transaction("UC05_TR09_Выход",LR_AUTO);

	return 0;
}