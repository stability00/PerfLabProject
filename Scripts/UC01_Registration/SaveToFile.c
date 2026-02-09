SaveToFile()
{
	file = fopen(lr_eval_string("{file_save_users}"), "a+");
	
	fseek(file, 0, 2);
	pos = ftell(file);
    if (pos == 0) {
        fprintf(file, "users,pass\n");
    }

	fprintf(file, "%s,%s\n", lr_eval_string("{ParticipantEmail}"), lr_eval_string("{pass_for_add}"));
	
    fclose(file);
	return 0;
}
