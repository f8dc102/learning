import org.junit.Test;
import static org.junit.Assert.*;

public class LectureTest {
    @Test public void testAppHasAGreeting() {
        App classUnderTest = new Lecture();
        assertNotNull("app should have a greeting", classUnderTest.getGreeting());
    }
}
