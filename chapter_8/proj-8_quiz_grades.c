/* Prompts for five quiz grades for each of five students,
 * then computes the total score and average score for each student,
 * and the average score, high score, and low score for each quiz.
 */

#include <stdio.h>

#define STUD_N 5
#define QUIZ_N 5

int main(void)
{
    int scores[STUD_N][QUIZ_N], per_student_sum, per_quiz_sum, high, low, score;

    for (int stud = 0; stud < STUD_N; stud++)
    {
        printf("Enter scores for student %d: ", stud + 1);

        for (int quiz = 0; quiz < QUIZ_N; quiz++)
            scanf("%d", &scores[stud][quiz]);
    }
    
    printf("\nStudent stats:\n");
    for (int stud = 0; stud < STUD_N; stud++)
    {
        per_student_sum = 0;
        
        for (int quiz = 0; quiz < QUIZ_N; quiz ++)
            per_student_sum += scores[stud][quiz];
        
        printf("Student %d - Total: %d, Average: %.2f\n",
                stud + 1, per_student_sum, (float) per_student_sum / QUIZ_N);
    }

    printf("\nQuiz stats:\n");
    for (int quiz = 0; quiz < QUIZ_N; quiz++)
    {
        per_quiz_sum = 0;
        high = scores[0][quiz];
        low = scores[0][quiz];
        
        for (int stud = 0; stud < STUD_N; stud++)
        {
            score = scores[stud][quiz];
            per_quiz_sum += score;

            if (score > high)
                high = score;
            else if (score < low)
                low = score;
        }
        
        printf("Quiz %d - Average: %.2f, High Score: %d, Low Score: %d\n",
            quiz + 1, (float) per_quiz_sum / QUIZ_N, high, low);
    }

    return 0;
}